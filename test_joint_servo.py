import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from control_msgs.msg import JointJog

class JointAutoMove(Node):
    def __init__(self):
        # Sync to Gazebo clock
        super().__init__('joint_teleop_override', 
                         parameter_overrides=[Parameter('use_sim_time', Parameter.Type.BOOL, True)])
        
        # Publish to the Joint command topic instead of Twist
        self.pub = self.create_publisher(JointJog, '/delta_joint_cmds', 10)
        self.timer = self.create_timer(0.05, self.timer_callback)

    def timer_callback(self):
        msg = JointJog()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'roarm_base_link'
        
        # REPLACE THESE WITH YOUR ACTUAL URDF JOINT NAMES
        msg.joint_names = ['base_link_to_link1', 'link1_to_link2', 'link2_to_link3'] 
        
        # Spin the first joint at 0.2 rad/s. Leave the others at 0.
        msg.velocities = [0.2, 0.0, 0.0] 
        
        self.pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = JointAutoMove()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
