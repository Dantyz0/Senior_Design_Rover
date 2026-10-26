import sys
import termios
import tty
import select
import json
import time
import serial

SERIAL_PORT = '/dev/ttyUSB0'
BAUD_RATE = 115200

try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
    ser.setDTR(False)
    ser.setRTS(False)
    print(f"Connected to ESP-NOW Magic Bridge on {SERIAL_PORT}")
    print(f"Waiting 2 seconds for ESP32 to boot")
    time.sleep(2)
except Exception as e:
    print(f"FATAL: Could not open {SERIAL_PORT}: {e}")
    sys.exit(1)

# FIX 1: Reset Start pos (same as home)
joints = {
    'b': {'val': 0.0,   'min': -3.14, 'max': 3.14},
    's': {'val': 0.0, 'min': -1.57, 'max': 1.57}, 
    'e': {'val': 1.57,  'min': 0.0,   'max': 3.14},
    'h': {'val': 3.14,  'min': 1.08,  'max': 3.14}
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

# FIX 2: Reset Home pos to Start pos
HOME_POSITION = {
    'b': 0.0,
    's': 0.0, 
    'e': 1.57,
    'h': 3.14
}

def send_serial_command(cmd_dict):
    try:
        payload = json.dumps(cmd_dict) + "\n"
        ser.write(payload.encode('utf-8'))
    except Exception:
        pass

def send_joint_command():
    # CRITICAL FIX 3: Reverted back to {T:"102"}
    # jailbreak: T:102 is now unlocked and executes as intended
    command = {
        "T": 102,
        "base": round(joints['b']['val'], 3),
        "shoulder": round(joints['s']['val'], 3),
        "elbow": round(joints['e']['val'], 3),
        "hand": round(joints['h']['val'], 3),
        "spd": 0
    }
    send_serial_command(command)

def toggle_led():
    global led_state
    led_state = 255 if led_state == 0 else 0
    # Send both "led" and "pwm" to ensure the parser catches it
    command = {"T": 114, "pwm": led_state, "led": led_state}
    send_serial_command(command)

def main():
    settings = termios.tcgetattr(sys.stdin)
    print("\nESP-NOW RoArm Teleop Active (Jailbreak Edition)")
    print("--------------------------------------------------")
    print("Arm: Q/E | Shoulder: W/S | Elbow: A/D")
    print("Gripper: O/P | Flashlight: L | Home: H")
    print("CTRL-C to quit\n")

    # Don't send a command immediately on boot
    # Wait for the user to press a key first.
    tty.setraw(sys.stdin.fileno())

    try:
        while True:
            if select.select([sys.stdin], [], [], 0.05)[0]:
                key = sys.stdin.read(1).lower()
                termios.tcflush(sys.stdin, termios.TCIFLUSH)

                if key in MOVE_BINDINGS:
                    j_id, step = MOVE_BINDINGS[key]
                    new_val = joints[j_id]['val'] + step
                    joints[j_id]['val'] = max(joints[j_id]['min'], min(new_val, joints[j_id]['max']))
                    send_joint_command()
                elif key in GRIPPER_BINDINGS:
                    joints['h']['val'] = GRIPPER_BINDINGS[key]
                    send_joint_command()
                elif key == 'h':
                    for k in HOME_POSITION: joints[k]['val'] = HOME_POSITION[k]
                    send_joint_command()
                elif key == 'l':
                    toggle_led()
                elif key == '\x03': 
                    break
    except Exception as e:
        sys.stdout.write(f"\r\nError: {e}\r\n")
    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        if ser.is_open: ser.close()
        print("\nDisconnected.")

if __name__ == '__main__':
    main()
