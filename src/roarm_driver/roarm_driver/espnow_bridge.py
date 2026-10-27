"""ESP-NOW Magic Bridge hardware interface for the RoArm-M2.

Talks to the ESP32 bridge over serial using the same JSON protocol as
espnow_teleop.py (T:102 joint moves, T:114 LED). Other nodes command the
arm by publishing sensor_msgs/JointState to /espnow/joint_command.
"""

import json
import time

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float32
from serial import Serial, SerialException


JOINT_NAMES = [
    'base_link_to_link1',
    'link1_to_link2',
    'link2_to_link3',
    'link3_to_gripper_link',
]

DEFAULT_POSITIONS = {
    'base_link_to_link1': 0.0,
    'link1_to_link2': 0.0,
    'link2_to_link3': 1.57,
    'link3_to_gripper_link': 3.14,
}

JOINT_LIMITS = {
    'base_link_to_link1': (-3.14, 3.14),
    'link1_to_link2': (-1.57, 1.57),
    'link2_to_link3': (0.0, 3.14),
    'link3_to_gripper_link': (1.08, 3.14),
}


class EspNowBridge(Node):
    def __init__(self):
        super().__init__('espnow_bridge')

        self.declare_parameter('serial_port', '/dev/ttyUSB0')
        self.declare_parameter('baud_rate', 115200)
        self.declare_parameter('boot_delay_sec', 2.0)
        self.declare_parameter('publish_rate_hz', 20.0)
        self.declare_parameter('send_home_on_start', False)
        self.declare_parameter('command_speed', 0)  # 0 = as-fast (matches teleop)

        port = self.get_parameter('serial_port').value
        baud = self.get_parameter('baud_rate').value
        boot_delay = self.get_parameter('boot_delay_sec').value
        self.command_speed = int(self.get_parameter('command_speed').value)

        self.positions = dict(DEFAULT_POSITIONS)
        self._ser = None

        try:
            self._ser = Serial(port, baud, timeout=0.1)
            self._ser.setDTR(False)
            self._ser.setRTS(False)
            self.get_logger().info(
                f'Connected to ESP-NOW Magic Bridge on {port} @ {baud}'
            )
            self.get_logger().info(f'Waiting {boot_delay:.1f}s for ESP32 boot...')
            time.sleep(boot_delay)
        except SerialException as exc:
            self.get_logger().fatal(f'Could not open {port}: {exc}')
            raise SystemExit(1) from exc

        self.joint_cmd_sub = self.create_subscription(
            JointState, '/espnow/joint_command', self.joint_command_callback, 10
        )
        self.led_sub = self.create_subscription(
            Float32, '/espnow/led', self.led_callback, 10
        )
        self.joint_state_pub = self.create_publisher(JointState, '/joint_states', 10)

        rate_hz = float(self.get_parameter('publish_rate_hz').value)
        self.create_timer(1.0 / max(rate_hz, 1.0), self.publish_joint_states)

        if self.get_parameter('send_home_on_start').value:
            self.send_joint_command()
            self.get_logger().info('Sent home pose on start.')

        self.get_logger().info(
            'ESP-NOW bridge ready. Command joints on /espnow/joint_command'
        )

    def clamp(self, name, value):
        lo, hi = JOINT_LIMITS[name]
        return max(lo, min(float(value), hi))

    def joint_command_callback(self, msg: JointState):
        if not msg.name or len(msg.name) != len(msg.position):
            self.get_logger().warn('Ignoring JointState with mismatched name/position')
            return

        updated = False
        for name, position in zip(msg.name, msg.position):
            if name not in self.positions:
                continue
            self.positions[name] = self.clamp(name, position)
            updated = True

        if updated:
            self.send_joint_command()

    def led_callback(self, msg: Float32):
        # Accept 0/255 style values (matches existing teleop) or 0.0/1.0
        value = float(msg.data)
        if 0.0 < value <= 1.0:
            pwm = 255 if value >= 0.5 else 0
        else:
            pwm = int(max(0, min(value, 255)))
        self.send_serial({'T': 114, 'pwm': pwm, 'led': pwm})

    def send_joint_command(self):
        command = {
            'T': 102,
            'base': round(self.positions['base_link_to_link1'], 3),
            'shoulder': round(self.positions['link1_to_link2'], 3),
            'elbow': round(self.positions['link2_to_link3'], 3),
            'hand': round(self.positions['link3_to_gripper_link'], 3),
            'spd': self.command_speed,
        }
        self.send_serial(command)

    def send_serial(self, command_dict):
        if self._ser is None or not self._ser.is_open:
            self.get_logger().error('Serial port not open')
            return
        try:
            payload = json.dumps(command_dict) + '\n'
            self._ser.write(payload.encode('utf-8'))
        except SerialException as exc:
            self.get_logger().error(f'Serial write failed: {exc}')

    def publish_joint_states(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = list(JOINT_NAMES)
        msg.position = [self.positions[n] for n in JOINT_NAMES]
        self.joint_state_pub.publish(msg)

    def destroy_node(self):
        if self._ser is not None and self._ser.is_open:
            self._ser.close()
            self.get_logger().info('ESP-NOW serial closed.')
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = EspNowBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
