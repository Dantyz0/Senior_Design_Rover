import sys
import termios
import tty
import serial
import json
import time

SERIAL_PORT = '/dev/ttyUSB0'  
BAUD_RATE = 115200

try:
    arm_serial = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
    print(f"Connected to {SERIAL_PORT}. Waiting 2 seconds for ESP32 to boot...")
    time.sleep(2)
except Exception as e:
    print(f"FATAL: Could not open {SERIAL_PORT}.")
    sys.exit(1)

joints = {
    'b': {'val': 0.0,  'min': -3.14, 'max': 3.14},
    's': {'val': 0.0,  'min': -1.57, 'max': 1.57},
    'e': {'val': 1.57, 'min': 0.0,   'max': 3.14},
    'h': {'val': 3.14, 'min': 1.08,  'max': 3.14}
}

led_state = 0  

STEP = 0.05 

MOVE_BINDINGS = {
    'q': ('b', STEP),  'e': ('b', -STEP),
    'w': ('s', STEP),  's': ('s', -STEP),
    'a': ('e', STEP),  'd': ('e', -STEP),
}

GRIPPER_BINDINGS = {
    'o': 1.08, 
    'p': 3.14  
}

HOME_POSITION = {
    'b': 0.0,
    's': 0.0,
    'e': 1.57,
    'h': 3.14
}

def send_joint_command():
    command = {
        "T": 102,
        "base": round(joints['b']['val'], 3),
        "shoulder": round(joints['s']['val'], 3),
        "elbow": round(joints['e']['val'], 3),
        "hand": round(joints['h']['val'], 3),
        "spd": 0
    }
    json_str = json.dumps(command) + '\n'
    arm_serial.write(json_str.encode('utf-8'))
    sys.stdout.write(f"\rSent: {json_str.strip()}      ")
    sys.stdout.flush()

def toggle_led():
    global led_state
    led_state = 255 if led_state == 0 else 0
    
    command = {
        "T": 114,
        "led": led_state
    }
    json_str = json.dumps(command) + '\n'
    arm_serial.write(json_str.encode('utf-8'))
    sys.stdout.write(f"\rSent: {json_str.strip()}      ")
    sys.stdout.flush()

def main():
    settings = termios.tcgetattr(sys.stdin)
    
    print("\nBare-Metal RoArm Teleop Active")
    print("---------------------------")
    print("Arm (Hold): Q/E | Shoulder: W/S | Elbow: A/D")
    print("Gripper (Click): O (Open) / P (Close)")
    print("Flashlight (Click): L (Toggle)")
    print("Home Position (Click): H")
    print("CTRL-C to quit\n")

    send_joint_command()
    tty.setraw(sys.stdin.fileno())

    try:
        while True:
            key = sys.stdin.read(1).lower()
            
            if key in MOVE_BINDINGS:
                j_id, step = MOVE_BINDINGS[key]
                new_val = joints[j_id]['val'] + step
                joints[j_id]['val'] = max(joints[j_id]['min'], min(new_val, joints[j_id]['max']))
                send_joint_command()
                
            elif key in GRIPPER_BINDINGS:
                joints['h']['val'] = GRIPPER_BINDINGS[key]
                send_joint_command()
                
            elif key == 'h':
                joints['b']['val'] = HOME_POSITION['b']
                joints['s']['val'] = HOME_POSITION['s']
                joints['e']['val'] = HOME_POSITION['e']
                joints['h']['val'] = HOME_POSITION['h']
                send_joint_command()
                
            elif key == 'l':
                toggle_led()
                
            elif key == '\x03': 
                break
            
            arm_serial.reset_input_buffer()

    except Exception as e:
        sys.stdout.write(f"\r\nError: {e}\r\n")
    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        arm_serial.close()
        print("\nDisconnected.")

if __name__ == '__main__':
    main()
