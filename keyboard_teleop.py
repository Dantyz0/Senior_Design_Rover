import sys
import termios
import tty
import select
import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from control_msgs.msg import JointJog
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from moveit_msgs.srv import ServoCommandType

# Keybindings: Velocities (rad/s)
MOVE_BINDINGS = {
    'q': ( 2.0,  0.0,  0.0), # Base Left
    'e': (-2.5,  0.0,  0.0), # Base Right
    'w': ( 0.0,  2.5,  0.0), # Link1 Up
    's': ( 0.0, -2.5,  0.0), # Link1 Down
    'a': ( 0.0,  0.0,  2.5), # Link2 Up
    'd': ( 0.0,  0.0, -2.5), # Link2 Down
}

GRIPPER_BINDINGS = {
    'o': 1.4,  # Open position 
    'p': 0.0,  # Closed position (Adjusted to match your log)
}

class RoverTeleop(Node):
    def __init__(self):
        super().__init__('rover_keyboard_teleop', 
                         parameter_overrides=[Parameter('use_sim_time', Parameter.Type.BOOL, True)])
        
        self.arm_pub = self.create_publisher(JointJog, '/servo_node/delta_joint_cmds', 10)
        self.gripper_pub = self.create_publisher(JointTrajectory, '/gripper_controller/joint_trajectory', 10)
        
        self.settings = termios.tcgetattr(sys.stdin)
        tty.setraw(sys.stdin.fileno())

        self.current_v = [0.0, 0.0, 0.0]
        self.current_gripper_target = None  # Memory lock for the gripper
        self.last_key_time = self.get_clock().now()

        self.timer = self.create_timer(0.05, self.timer_callback)

    def lock_servo_mode(self):
        cli = self.create_client(ServoCommandType, '/servo_node/switch_command_type')
        if cli.wait_for_service(timeout_sec=2.0):
            req = ServoCommandType.Request()
            req.command_type = 1 
            future = cli.call_async(req)
            rclpy.spin_until_future_complete(self, future)
            print("SUCCESS: Servo locked into Joint Mode!\r")

    def timer_callback(self):
        rlist, _, _ = select.select([sys.stdin], [], [], 0.0)
        
        if rlist:
            key = sys.stdin.read(1)
            self.last_key_time = self.get_clock().now()
            
            if key in MOVE_BINDINGS:
                self.current_v = list(MOVE_BINDINGS[key])
            elif key in GRIPPER_BINDINGS:
                target = GRIPPER_BINDINGS[key]
                # Only publish if the target has actually changed
                if target != self.current_gripper_target:
                    self.publish_gripper(target)
                    self.current_gripper_target = target
            elif key == '\x03': 
                raise SystemExit
        
        time_since_key = (self.get_clock().now() - self.last_key_time).nanoseconds / 1e9
        if time_since_key > 0.4:
            self.current_v = [0.0, 0.0, 0.0]

        self.publish_arm(*self.current_v)

    def publish_arm(self, v1, v2, v3):
        msg = JointJog()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'roarm_base_link'
        msg.joint_names = ['base_link_to_link1', 'link1_to_link2', 'link2_to_link3']
        msg.velocities = [float(v1), float(v2), float(v3)]
        self.arm_pub.publish(msg)

    def publish_gripper(self, position):
        msg = JointTrajectory()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.joint_names = ['link3_to_gripper_link']
        
        point = JointTrajectoryPoint()
        point.positions = [float(position)]
        # Increased to 2 seconds to satisfy your URDF 1.0 rad/s velocity limit
        point.time_from_start.sec = 2 
        msg.points = [point]
        self.gripper_pub.publish(msg)

    def restore_terminal(self):
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)

def main():
    rclpy.init()
    node = RoverTeleop()
    
    node.lock_servo_mode()
    
    print("\r\nRover Teleop Active\r")
    print("---------------------------\r")
    print("Arm (Hold): Q/E, W/S, A/D\r")
    print("Gripper (Press): O/P\r")
    print("CTRL-C to quit\r\n")

    try:
        rclpy.spin(node)
    except SystemExit:
        pass
    except Exception as e:
        print(f"Error: {e}\r")
    finally:
        node.publish_arm(0.0, 0.0, 0.0)
        node.restore_terminal()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
