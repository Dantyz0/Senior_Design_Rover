"""Keyboard teleop that publishes JointState commands to /espnow/joint_command.

Requires espnow_bridge to be running.
"""

import sys
import termios
import tty
import select

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float32


STEP = 0.05

MOVE_BINDINGS = {
    'q': ('base_link_to_link1', STEP),
    'e': ('base_link_to_link1', -STEP),
    'w': ('link1_to_link2', STEP),
    's': ('link1_to_link2', -STEP),
    'a': ('link2_to_link3', STEP),
    'd': ('link2_to_link3', -STEP),
}

GRIPPER_OPEN = 1.08
GRIPPER_CLOSED = 3.14

HOME = {
    'base_link_to_link1': 0.0,
    'link1_to_link2': 0.0,
    'link2_to_link3': 1.57,
    'link3_to_gripper_link': 3.14,
}

LIMITS = {
    'base_link_to_link1': (-3.14, 3.14),
    'link1_to_link2': (-1.57, 1.57),
    'link2_to_link3': (0.0, 3.14),
    'link3_to_gripper_link': (1.08, 3.14),
}


class EspNowKeyboardTeleop(Node):
    def __init__(self):
        super().__init__('espnow_keyboard_teleop')
        self.positions = dict(HOME)
        self.led_on = False

        self.cmd_pub = self.create_publisher(JointState, '/espnow/joint_command', 10)
        self.led_pub = self.create_publisher(Float32, '/espnow/led', 10)

        self.settings = termios.tcgetattr(sys.stdin)
        tty.setraw(sys.stdin.fileno())
        self.create_timer(0.05, self.poll_keyboard)

        self._print_help()

    def _print_help(self):
        sys.stdout.write(
            '\r\nESP-NOW ROS Teleop\r\n'
            '---------------------------\r\n'
            'Base: Q/E | Shoulder: W/S | Elbow: A/D\r\n'
            'Gripper: O open / P close | Home: H | LED: L\r\n'
            'CTRL-C to quit\r\n\r\n'
        )
        sys.stdout.flush()

    def clamp(self, name, value):
        lo, hi = LIMITS[name]
        return max(lo, min(value, hi))

    def publish_command(self, names=None):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        if names is None:
            names = list(self.positions.keys())
        msg.name = list(names)
        msg.position = [self.positions[n] for n in names]
        self.cmd_pub.publish(msg)

    def poll_keyboard(self):
        if not select.select([sys.stdin], [], [], 0.0)[0]:
            return

        key = sys.stdin.read(1).lower()
        termios.tcflush(sys.stdin, termios.TCIFLUSH)

        if key in MOVE_BINDINGS:
            joint, delta = MOVE_BINDINGS[key]
            self.positions[joint] = self.clamp(joint, self.positions[joint] + delta)
            self.publish_command([joint])
            self._echo_pose()
        elif key == 'o':
            self.positions['link3_to_gripper_link'] = GRIPPER_OPEN
            self.publish_command(['link3_to_gripper_link'])
            self._echo_pose()
        elif key == 'p':
            self.positions['link3_to_gripper_link'] = GRIPPER_CLOSED
            self.publish_command(['link3_to_gripper_link'])
            self._echo_pose()
        elif key == 'h':
            self.positions = dict(HOME)
            self.publish_command()
            self._echo_pose()
        elif key == 'l':
            self.led_on = not self.led_on
            msg = Float32()
            msg.data = 255.0 if self.led_on else 0.0
            self.led_pub.publish(msg)
            sys.stdout.write(f'\rLED {"ON" if self.led_on else "OFF"}          \r\n')
            sys.stdout.flush()
        elif key == '\x03':
            raise SystemExit

    def _echo_pose(self):
        p = self.positions
        sys.stdout.write(
            f"\rb={p['base_link_to_link1']:.2f} "
            f"s={p['link1_to_link2']:.2f} "
            f"e={p['link2_to_link3']:.2f} "
            f"h={p['link3_to_gripper_link']:.2f}   "
        )
        sys.stdout.flush()

    def restore_terminal(self):
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)


def main(args=None):
    rclpy.init(args=args)
    node = EspNowKeyboardTeleop()
    try:
        rclpy.spin(node)
    except SystemExit:
        pass
    except KeyboardInterrupt:
        pass
    finally:
        node.restore_terminal()
        node.destroy_node()
        rclpy.shutdown()
        print('\nTeleop stopped.')


if __name__ == '__main__':
    main()
