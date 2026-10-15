import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Twist, Point
from sensor_msgs.msg import NavSatFix
from nav_msgs.msg import Odometry
import math
import threading

# ==========================================
# NODE 1: GPS TRANSLATOR
# ==========================================
class GPSTranslator(Node):
    def __init__(self):
        super().__init__('gps_translator')
        
        # Default origin set to Salina campus for capstone field testing
        self.home_lat = 38.793000
        self.home_lon = -97.583000
        self.meters_per_deg_lat = 111320.0
        
        self.gps_sub = self.create_subscription(NavSatFix, '/drone_gps', self.gps_callback, 10)
        self.target_pub = self.create_publisher(Point, '/target_coordinate', 10)
        
        self.get_logger().info('GPS Translator active. Waiting for /drone_gps handoff...')

    def gps_callback(self, msg):
        delta_lat = msg.latitude - self.home_lat
        delta_lon = msg.longitude - self.home_lon
        
        x_meters = delta_lon * self.meters_per_deg_lat * math.cos(math.radians(self.home_lat))
        y_meters = delta_lat * self.meters_per_deg_lat
        
        point_msg = Point()
        point_msg.x = x_meters
        point_msg.y = y_meters
        point_msg.z = 0.0
        
        self.target_pub.publish(point_msg)
        self.get_logger().info(f"Drone GPS [{msg.latitude:.6f}, {msg.longitude:.6f}] translated to Gazebo [X: {x_meters:.2f}m, Y: {y_meters:.2f}m]")


# ==========================================
# NODE 2: MISSION CONTROLLER
# ==========================================
class MissionController(Node):
    def __init__(self):
        super().__init__('mission_controller')
        
        # System Mission States
        self.state = 'WAITING_FOR_GPS'
        self.ducks_collected = 0
        self.max_ducks = 3
        self.prompt_active = False  
        
        # Hardcoded Route Coordinates
        self.home_x = 0.0
        self.home_y = 0.0
        self.dropoff_x = -1.0
        self.dropoff_y = 2.0
        
        # Dynamic Target Coordinates
        self.current_x = 0.0
        self.current_y = 0.0
        self.current_yaw = 0.0
        self.target_x = 0.0  
        self.target_y = 0.0
        
        # Publishers & Subscribers
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.odom_sub = self.create_subscription(Odometry, '/odom', self.odom_callback, 10)
        self.target_sub = self.create_subscription(Point, '/target_coordinate', self.target_callback, 10)
        
        self.timer = self.create_timer(0.1, self.mission_loop)
        self.get_logger().info('Mission Controller active. Ready for deployment.')

    def target_callback(self, msg):
        if self.state == 'WAITING_FOR_GPS':
            self.target_x = msg.x
            self.target_y = msg.y
            self.state = 'AUTONOMOUS_APPROACH'
            self.get_logger().info(f'Local coordinate received. Approaching Duck {self.ducks_collected + 1}.')
        else:
            self.get_logger().warn('Coordinate received, but rover is currently busy.')

    def odom_callback(self, msg):
        self.current_x = msg.pose.pose.position.x
        self.current_y = msg.pose.pose.position.y
        
        q = msg.pose.pose.orientation
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        self.current_yaw = math.atan2(siny_cosp, cosy_cosp)

    def get_distance_to_target(self):
        return math.hypot(self.target_x - self.current_x, self.target_y - self.current_y)

    def mission_loop(self):
        if self.state == 'WAITING_FOR_GPS':
            pass

        elif self.state == 'AUTONOMOUS_APPROACH':
            distance = self.get_distance_to_target()
            if distance > 3.0:
                self.drive_towards_target(speed=2.0)
            elif 0.6 < distance <= 3.0:
                self.drive_towards_target(speed=0.5)
            else:
                self.state = 'MANUAL_RETRIEVAL'
                self.prompt_active = False

        elif self.state == 'MANUAL_RETRIEVAL':
            self.halt_rover()
            if not self.prompt_active:
                self.prompt_active = True
                threading.Thread(target=self.duck_pickup_prompt).start()

        elif self.state == 'AUTONOMOUS_DROPOFF':
            distance = self.get_distance_to_target()
            if distance > 0.6:
                self.drive_towards_target(speed=2.0)
            else:
                self.state = 'MANUAL_UNLOAD'
                self.prompt_active = False

        elif self.state == 'MANUAL_UNLOAD':
            self.halt_rover()
            if not self.prompt_active:
                self.prompt_active = True
                threading.Thread(target=self.dropoff_prompt).start()

        elif self.state == 'AUTONOMOUS_RETURN_HOME':
            distance = self.get_distance_to_target()
            if distance > 0.6:
                self.drive_towards_target(speed=2.0)
            else:
                self.state = 'MISSION_COMPLETE'
                
        elif self.state == 'MISSION_COMPLETE':
            self.halt_rover()
            if not self.prompt_active:
                self.prompt_active = True
                self.get_logger().info('>>> MISSION COMPLETE. ROVER SECURED AT HOME. <<<')

    def duck_pickup_prompt(self):
        print(f"\n>>> ARRIVED AT DUCK {self.ducks_collected + 1} <<<")
        print(">>> SYSTEM PAUSED. MANUAL COLLECTION OVERRIDE ACTIVE. <<<")
        print("  1. Switch to RViz.")
        print("  2. Plan and execute trajectory to grab the duck.")
        input("  3. PRESS [ENTER] TO RESUME MISSION...")
        
        self.ducks_collected += 1
        if self.ducks_collected >= self.max_ducks:
            self.get_logger().info('All 3 ducks secured. Navigating to drop-off zone.')
            self.target_x = self.dropoff_x
            self.target_y = self.dropoff_y
            self.state = 'AUTONOMOUS_DROPOFF'
        else:
            self.get_logger().info('Waiting for next coordinate handoff...')
            self.state = 'WAITING_FOR_GPS'

    def dropoff_prompt(self):
        print("\n>>> ARRIVED AT DROP-OFF ZONE <<<")
        print(">>> SYSTEM PAUSED. MANUAL UNLOAD ACTIVE. <<<")
        print("  1. Switch to RViz and unload the ducks.")
        input("  2. PRESS [ENTER] AFTER UNLOADING TO RETURN HOME...")
        
        self.get_logger().info('Ducks unloaded. Navigating to Home Base.')
        self.target_x = self.home_x
        self.target_y = self.home_y
        self.state = 'AUTONOMOUS_RETURN_HOME'

    def drive_towards_target(self, speed):
        angle_to_target = math.atan2(self.target_y - self.current_y, self.target_x - self.current_x)
        heading_error = angle_to_target - self.current_yaw
        heading_error = math.atan2(math.sin(heading_error), math.cos(heading_error))
        
        msg = Twist()
        msg.angular.z = 2.5 * heading_error 
        
        if abs(heading_error) > 0.25:
            msg.linear.x = 0.0
        else:
            msg.linear.x = speed
            
        self.cmd_pub.publish(msg)

    def halt_rover(self):
        msg = Twist()
        self.cmd_pub.publish(msg)

# ==========================================
# MAIN EXECUTION THREAD
# ==========================================
def main(args=None):
    rclpy.init(args=args)
    
    # Initialize both nodes
    mission_node = MissionController()
    gps_node = GPSTranslator()

    # Create a MultiThreadedExecutor to run them both at the same time
    executor = MultiThreadedExecutor()
    executor.add_node(mission_node)
    executor.add_node(gps_node)

    # Spin the executor in a background thread so the input() prompts don't freeze the system
    spin_thread = threading.Thread(target=executor.spin)
    spin_thread.start()

    try:
        # Keep the main thread alive while the background threads do the work
        spin_thread.join()
    except KeyboardInterrupt:
        print("\nMission Aborted by User.")
    finally:
        executor.shutdown()
        mission_node.destroy_node()
        gps_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
