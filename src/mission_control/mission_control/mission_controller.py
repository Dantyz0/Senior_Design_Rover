import math
import sys
import threading

import rclpy
from geometry_msgs.msg import Point, Twist
from nav_msgs.msg import Odometry
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import NavSatStatus
from std_msgs.msg import Bool
from std_srvs.srv import Trigger

from mission_control.geo import wgs84_to_enu


class GPSTranslator(Node):
    """Convert duck WGS84 fixes into local ENU meters for the mission node."""

    def __init__(self):
        super().__init__('gps_translator')

        self.declare_parameter('home_lat', 38.793000)
        self.declare_parameter('home_lon', -97.583000)

        self.home_lat = float(self.get_parameter('home_lat').value)
        self.home_lon = float(self.get_parameter('home_lon').value)

        self.gps_sub = self.create_subscription(
            NavSatFix, '/drone_gps', self.gps_callback, 10
        )
        self.target_pub = self.create_publisher(Point, '/target_coordinate', 10)

        self.get_logger().info(
            f'GPS Translator ready. Origin lat={self.home_lat:.6f} '
            f'lon={self.home_lon:.6f} (x=east, y=north). Waiting on /drone_gps'
        )

    def gps_callback(self, msg: NavSatFix):
        if msg.status.status < NavSatStatus.STATUS_FIX:
            self.get_logger().warning('Ignoring /drone_gps with no fix')
            return

        east_m, north_m = wgs84_to_enu(
            msg.latitude, msg.longitude, self.home_lat, self.home_lon
        )

        point_msg = Point()
        point_msg.x = east_m
        point_msg.y = north_m
        point_msg.z = 0.0
        self.target_pub.publish(point_msg)

        self.get_logger().info(
            f'Drone GPS [{msg.latitude:.6f}, {msg.longitude:.6f}] -> '
            f'ENU/Gazebo [E/X {east_m:.2f} m, N/Y {north_m:.2f} m]'
        )


class MissionController(Node):
    def __init__(self):
        super().__init__('mission_controller')

        self.declare_parameter('home_x', 0.0)
        self.declare_parameter('home_y', 0.0)
        self.declare_parameter('dropoff_x', 6.0)
        self.declare_parameter('dropoff_y', 4.0)
        self.declare_parameter('max_ducks', 3)
        self.declare_parameter('slow_distance_m', 3.048)  # 10 ft
        self.declare_parameter('stop_distance_m', 0.3048)  # 1 ft
        self.declare_parameter('cruise_speed', 1.0)
        self.declare_parameter('approach_speed', 0.25)
        self.declare_parameter('heading_kp', 1.8)
        self.declare_parameter('heading_deadband', 0.35)
        self.declare_parameter('dump_pulse_sec', 1.5)

        self.state = 'WAITING_FOR_GPS'
        self.ducks_collected = 0
        self.max_ducks = int(self.get_parameter('max_ducks').value)
        self.prompt_active = False
        self.dump_deadline = None

        self.home_x = float(self.get_parameter('home_x').value)
        self.home_y = float(self.get_parameter('home_y').value)
        self.dropoff_x = float(self.get_parameter('dropoff_x').value)
        self.dropoff_y = float(self.get_parameter('dropoff_y').value)
        self.slow_distance_m = float(self.get_parameter('slow_distance_m').value)
        self.stop_distance_m = float(self.get_parameter('stop_distance_m').value)
        self.cruise_speed = float(self.get_parameter('cruise_speed').value)
        self.approach_speed = float(self.get_parameter('approach_speed').value)
        self.heading_kp = float(self.get_parameter('heading_kp').value)
        self.heading_deadband = float(self.get_parameter('heading_deadband').value)
        self.dump_pulse_sec = float(self.get_parameter('dump_pulse_sec').value)

        self.current_x = 0.0
        self.current_y = 0.0
        self.current_yaw = 0.0
        self.target_x = 0.0
        self.target_y = 0.0
        self.have_odom = False

        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.dump_pub = self.create_publisher(Bool, '/dump_bed', 10)
        self.odom_sub = self.create_subscription(
            Odometry, '/odom', self.odom_callback, qos_profile_sensor_data
        )
        self.target_sub = self.create_subscription(
            Point, '/target_coordinate', self.target_callback, 10
        )
        self.confirm_srv = self.create_service(
            Trigger, '/mission/confirm_pickup', self.confirm_pickup_cb
        )

        self.timer = self.create_timer(0.1, self.mission_loop)
        self.get_logger().info(
            'Mission ready: wait GPS → drive (slow @ 10 ft, stop @ 1 ft) → '
            'manual arm → x3 → dump solenoid → home.'
        )

    def target_callback(self, msg: Point):
        if self.state == 'WAITING_FOR_GPS':
            self.target_x = msg.x
            self.target_y = msg.y
            self.state = 'AUTONOMOUS_APPROACH'
            self.get_logger().info(
                f'Local target received. Approaching duck '
                f'{self.ducks_collected + 1}/{self.max_ducks} '
                f'at x={self.target_x:.2f} y={self.target_y:.2f}'
            )
        else:
            self.get_logger().warning('GPS received, but rover is busy. Ignoring.')

    def odom_callback(self, msg: Odometry):
        self.current_x = msg.pose.pose.position.x
        self.current_y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        self.current_yaw = math.atan2(siny_cosp, cosy_cosp)
        self.have_odom = True

    def get_distance_to_target(self):
        return math.hypot(self.target_x - self.current_x, self.target_y - self.current_y)

    def mission_loop(self):
        if self.state == 'WAITING_FOR_GPS':
            self.halt_rover()
            return

        if self.state in (
            'AUTONOMOUS_APPROACH',
            'AUTONOMOUS_DROPOFF',
            'AUTONOMOUS_RETURN_HOME',
        ) and not self.have_odom:
            self.get_logger().warning(
                'Waiting for /odom before driving...', throttle_duration_sec=2.0
            )
            self.halt_rover()
            return

        if self.state == 'AUTONOMOUS_APPROACH':
            distance = self.get_distance_to_target()
            if distance > self.slow_distance_m:
                self.drive_towards_target(self.cruise_speed)
            elif distance > self.stop_distance_m:
                self.drive_towards_target(self.approach_speed)
            else:
                self.halt_rover()
                self.state = 'MANUAL_RETRIEVAL'
                self.prompt_active = False
                self.get_logger().info(
                    f'Stopped {distance:.2f} m from duck. Manual arm pickup.'
                )

        elif self.state == 'MANUAL_RETRIEVAL':
            self.halt_rover()
            if not self.prompt_active:
                self.prompt_active = True
                threading.Thread(target=self.duck_pickup_prompt, daemon=True).start()

        elif self.state == 'AUTONOMOUS_DROPOFF':
            distance = self.get_distance_to_target()
            if distance > self.slow_distance_m:
                self.drive_towards_target(self.cruise_speed)
            elif distance > self.stop_distance_m:
                self.drive_towards_target(self.approach_speed)
            else:
                self.halt_rover()
                self.state = 'DUMPING'
                self.dump_deadline = self.get_clock().now() + rclpy.duration.Duration(
                    seconds=self.dump_pulse_sec
                )
                self.set_dump_bed(True)
                self.get_logger().info('At drop-off. Pulsing dump-bed solenoid.')

        elif self.state == 'DUMPING':
            self.halt_rover()
            if self.dump_deadline is not None and self.get_clock().now() >= self.dump_deadline:
                self.set_dump_bed(False)
                self.dump_deadline = None
                self.target_x = self.home_x
                self.target_y = self.home_y
                self.state = 'AUTONOMOUS_RETURN_HOME'
                self.get_logger().info('Dump complete. Returning home.')

        elif self.state == 'AUTONOMOUS_RETURN_HOME':
            distance = self.get_distance_to_target()
            if distance > self.slow_distance_m:
                self.drive_towards_target(self.cruise_speed)
            elif distance > self.stop_distance_m:
                self.drive_towards_target(self.approach_speed)
            else:
                self.halt_rover()
                self.state = 'MISSION_COMPLETE'

        elif self.state == 'MISSION_COMPLETE':
            self.halt_rover()
            if not self.prompt_active:
                self.prompt_active = True
                self.get_logger().info('>>> MISSION COMPLETE. ROVER SECURED AT HOME. <<<')

    def duck_pickup_prompt(self):
        n = self.ducks_collected + 1
        print(f'\n>>> ARRIVED AT DUCK {n}/{self.max_ducks} <<<')
        print('>>> BASE HALTED. Click this terminal and PRESS ENTER when loaded. <<<')
        sys.stdout.flush()
        try:
            input()
        except EOFError:
            self.get_logger().error('No keyboard attached; cannot wait for Enter.')
            return

        if self.state == 'MANUAL_RETRIEVAL':
            self._complete_pickup()

    def confirm_pickup_cb(self, _request, response):
        if self.state != 'MANUAL_RETRIEVAL':
            response.success = False
            response.message = f'Not waiting for pickup (state={self.state})'
            return response
        self._complete_pickup()
        response.success = True
        response.message = f'Duck {self.ducks_collected}/{self.max_ducks} confirmed'
        return response

    def _complete_pickup(self):
        self.ducks_collected += 1
        if self.ducks_collected >= self.max_ducks:
            self.get_logger().info('All ducks loaded. Driving to drop-off.')
            self.target_x = self.dropoff_x
            self.target_y = self.dropoff_y
            self.state = 'AUTONOMOUS_DROPOFF'
        else:
            self.get_logger().info('Waiting for next /drone_gps handoff...')
            self.state = 'WAITING_FOR_GPS'
        self.prompt_active = False

    def set_dump_bed(self, down: bool):
        msg = Bool()
        msg.data = down
        self.dump_pub.publish(msg)

    def drive_towards_target(self, speed):
        angle_to_target = math.atan2(
            self.target_y - self.current_y, self.target_x - self.current_x
        )
        heading_error = math.atan2(
            math.sin(angle_to_target - self.current_yaw),
            math.cos(angle_to_target - self.current_yaw),
        )

        msg = Twist()
        msg.angular.z = self.heading_kp * heading_error
        if abs(heading_error) > self.heading_deadband:
            msg.linear.x = 0.0
        else:
            msg.linear.x = speed
        self.cmd_pub.publish(msg)

    def halt_rover(self):
        self.cmd_pub.publish(Twist())


def _attach_terminal():
    """ros2 launch does not pass stdin; bind the real terminal so Enter works."""
    try:
        if not sys.stdin.isatty():
            sys.stdin = open('/dev/tty', encoding='utf-8')
        if not sys.stdout.isatty():
            sys.stdout = open('/dev/tty', 'w', encoding='utf-8', buffering=1)
    except OSError:
        pass


def main(args=None):
    _attach_terminal()
    rclpy.init(args=args)

    mission_node = MissionController()
    gps_node = GPSTranslator()

    executor = MultiThreadedExecutor()
    executor.add_node(mission_node)
    executor.add_node(gps_node)

    spin_thread = threading.Thread(target=executor.spin, daemon=True)
    spin_thread.start()

    try:
        spin_thread.join()
    except KeyboardInterrupt:
        print('\nMission aborted by user.')
    finally:
        mission_node.halt_rover()
        mission_node.set_dump_bed(False)
        executor.shutdown()
        mission_node.destroy_node()
        gps_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
