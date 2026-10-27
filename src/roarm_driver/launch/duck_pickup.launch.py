"""Duck-pickup pose trainer. Start the bridge first:

  ros2 launch roarm_driver espnow_arm.launch.py
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    poses_yaml = os.path.join(
        get_package_share_directory('roarm_driver'), 'config', 'arm_poses.yaml'
    )

    return LaunchDescription([
        Node(
            package='roarm_driver',
            executable='duck_pickup',
            name='espnow_duck_pickup',
            output='screen',
            emulate_tty=True,
            parameters=[{'poses_file': poses_yaml, 'settle_sec': 1.5}],
        ),
    ])
