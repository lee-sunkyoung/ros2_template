# ros2_demo.launch.py
# this provides more specific expressions than .yaml model. 
 
import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_demo',
            executable='ros2_demo',
            name='pubsub_node',
            output='screen',
            parameters=[{'initial_value': 10}],
        )
    ])
