import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import SetParameter
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_dir = get_package_share_directory('rover_moveit_config')
    
    return LaunchDescription([
        # Safely force the simulation time strictly as a boolean
        SetParameter(name='use_sim_time', value=True),
        
        # Launch MoveIt and RViz together
        IncludeLaunchDescription(PythonLaunchDescriptionSource(os.path.join(pkg_dir, 'launch', 'move_group.launch.py'))),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(os.path.join(pkg_dir, 'launch', 'moveit_rviz.launch.py'))),

        # Launch MoveIt Servo in the background
        IncludeLaunchDescription(PythonLaunchDescriptionSource(os.path.join(pkg_dir, 'launch', 'servo.launch.py')))
    ])
