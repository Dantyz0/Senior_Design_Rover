"""Tabletop duck-pickup pose trainer for the ESP-NOW RoArm.

Publishes named joint poses to /espnow/joint_command. Tune poses in
config/arm_poses.yaml, then step through them on the real arm.

Keys:
  1 home | 2 approach | 3 grasp | 4 lift | 5 tuck
  space  run full sequence
  CTRL-C quit
"""

import sys
import termios
import tty
import select
from pathlib import Path

import yaml
import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory
from sensor_msgs.msg import JointState
from std_srvs.srv import Trigger


DEFAULT_POSES = {
    'home': {
        'base_link_to_link1': 0.0,
        'link1_to_link2': 0.0,
        'link2_to_link3': 1.57,
        'link3_to_gripper_link': 3.14,
    },
    'approach': {
        'base_link_to_link1': 0.0,
        'link1_to_link2': -0.6,
        'link2_to_link3': 1.8,
        'link3_to_gripper_link': 1.08,
    },
    'grasp': {
        'base_link_to_link1': 0.0,
        'link1_to_link2': -0.6,
        'link2_to_link3': 1.8,
        'link3_to_gripper_link': 3.14,
    },
    'lift': {
        'base_link_to_link1': 0.0,
        'link1_to_link2': -0.2,
        'link2_to_link3': 1.4,
        'link3_to_gripper_link': 3.14,
    },
    'tuck': {
        'base_link_to_link1': 0.8,
        'link1_to_link2': 0.0,
        'link2_to_link3': 1.57,
        'link3_to_gripper_link': 3.14,
    },
}

DEFAULT_SEQUENCE = ['approach', 'grasp', 'lift', 'tuck']

KEY_TO_POSE = {
    '1': 'home',
    '2': 'approach',
    '3': 'grasp',
    '4': 'lift',
    '5': 'tuck',
}


def default_poses_path():
    try:
        share = get_package_share_directory('roarm_driver')
        return str(Path(share) / 'config' / 'arm_poses.yaml')
    except Exception:
        return ''


class DuckPickup(Node):
    def __init__(self):
        super().__init__('espnow_duck_pickup')

        self.declare_parameter('poses_file', default_poses_path())
        self.declare_parameter('settle_sec', 1.5)

        self.poses = {name: dict(joints) for name, joints in DEFAULT_POSES.items()}
        self.sequence = list(DEFAULT_SEQUENCE)
        self.settle_sec = float(self.get_parameter('settle_sec').value)

        self._load_poses_file(self.get_parameter('poses_file').value)

        self.cmd_pub = self.create_publisher(JointState, '/espnow/joint_command', 10)
        self.seq_srv = self.create_service(Trigger, '~/run_sequence', self.run_sequence_cb)

        self._running_sequence = False
        self._seq_index = 0
        self._seq_deadline = None

        self.settings = termios.tcgetattr(sys.stdin)
        tty.setraw(sys.stdin.fileno())
        self.create_timer(0.05, self.tick)

        self._print_help()
        self.get_logger().info(
            f'Loaded poses: {list(self.poses.keys())}; sequence={self.sequence}'
        )

    def _load_poses_file(self, path: str):
        if not path:
            self.get_logger().warn('No poses_file set; using built-in defaults')
            return

        poses_path = Path(path)
        if not poses_path.is_file():
            self.get_logger().warn(f'poses_file not found: {path}; using defaults')
            return

        with poses_path.open('r', encoding='utf-8') as f:
            data = yaml.safe_load(f) or {}

        # Accept either raw keys or the ros__parameters wrapper used by launch
        params = data
        if 'espnow_duck_pickup' in data:
            params = data['espnow_duck_pickup'].get('ros__parameters', {})
        elif 'ros__parameters' in data:
            params = data['ros__parameters']

        if 'settle_sec' in params:
            self.settle_sec = float(params['settle_sec'])
        if 'sequence' in params and params['sequence']:
            self.sequence = list(params['sequence'])
        if 'poses' in params and isinstance(params['poses'], dict):
            for pose_name, joints in params['poses'].items():
                self.poses[pose_name] = {str(k): float(v) for k, v in joints.items()}

        self.get_logger().info(f'Loaded poses from {path}')

    def _print_help(self):
        sys.stdout.write(
            '\r\nDuck Pickup Pose Trainer\r\n'
            '---------------------------\r\n'
            '1 home | 2 approach | 3 grasp | 4 lift | 5 tuck\r\n'
            'SPACE run full sequence | CTRL-C quit\r\n'
            'Tune joints in config/arm_poses.yaml then restart this node\r\n\r\n'
        )
        sys.stdout.flush()

    def publish_pose(self, pose_name: str):
        if pose_name not in self.poses:
            self.get_logger().error(f'Unknown pose: {pose_name}')
            return False

        joints = self.poses[pose_name]
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = list(joints.keys())
        msg.position = [float(joints[n]) for n in msg.name]
        self.cmd_pub.publish(msg)

        sys.stdout.write(
            f'\r>> pose: {pose_name}   {dict(zip(msg.name, [round(p, 3) for p in msg.position]))}\r\n'
        )
        sys.stdout.flush()
        self.get_logger().info(f'Sent pose "{pose_name}"')
        return True

    def start_sequence(self):
        if self._running_sequence:
            self.get_logger().warn('Sequence already running')
            return False
        if not self.sequence:
            self.get_logger().error('Empty sequence')
            return False

        self._running_sequence = True
        self._seq_index = 0
        self._seq_deadline = None
        sys.stdout.write('\r>> running sequence...\r\n')
        sys.stdout.flush()
        return True

    def run_sequence_cb(self, _request, response):
        ok = self.start_sequence()
        response.success = ok
        response.message = 'started' if ok else 'busy or empty'
        return response

    def tick(self):
        if self._running_sequence:
            now = self.get_clock().now()
            if self._seq_deadline is None:
                pose = self.sequence[self._seq_index]
                self.publish_pose(pose)
                self._seq_deadline = now + rclpy.duration.Duration(seconds=self.settle_sec)
            elif now >= self._seq_deadline:
                self._seq_index += 1
                if self._seq_index >= len(self.sequence):
                    self._running_sequence = False
                    self._seq_deadline = None
                    sys.stdout.write('\r>> sequence complete\r\n')
                    sys.stdout.flush()
                    self.get_logger().info('Duck pickup sequence complete')
                else:
                    self._seq_deadline = None

        if not select.select([sys.stdin], [], [], 0.0)[0]:
            return

        key = sys.stdin.read(1).lower()
        termios.tcflush(sys.stdin, termios.TCIFLUSH)

        if key == '\x03':
            raise SystemExit
        if key == ' ':
            self.start_sequence()
            return
        if key in KEY_TO_POSE:
            if self._running_sequence:
                self.get_logger().warn('Wait for the sequence to finish')
                return
            self.publish_pose(KEY_TO_POSE[key])

    def restore_terminal(self):
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)


def main(args=None):
    rclpy.init(args=args)
    node = DuckPickup()
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
        print('\nDuck pickup trainer stopped.')


if __name__ == '__main__':
    main()
