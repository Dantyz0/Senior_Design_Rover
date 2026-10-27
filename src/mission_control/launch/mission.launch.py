import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetParameter
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    params = os.path.join(
        get_package_share_directory('mission_control'), 'config', 'mission.yaml'
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        SetParameter(
            name='use_sim_time',
            value=ParameterValue(LaunchConfiguration('use_sim_time'), value_type=bool),
        ),
        Node(
            package='mission_control',
            executable='controller',
            output='screen',
            emulate_tty=True,
            parameters=[params],
        ),
    ])
