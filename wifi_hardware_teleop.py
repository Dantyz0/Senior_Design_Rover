import sys
import termios
import tty
import select
import requests
import json
import time
import threading

# ==========================================
# 1. YOUR ROBOT SETTINGS
# ==========================================
ROBOT_IP = '192.168.4.1'

print(f"Pinging {ROBOT_IP}...")
try:
    requests.get(f"http://{ROBOT_IP}/", timeout=2)
    print("SUCCESS: Connected to RoArm-M2-S wirelessly.")
except Exception as e:
    print(f"FATAL: Could not reach {ROBOT_IP}. Is the arm on the same Wi-Fi?")
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

# ==========================================
# 2. BACKGROUND NETWORK WORKER (Zero Lag)
# ==========================================
latest_command = None

def network_worker():
    global latest_command
    while True:
        if latest_command is not None:
            cmd_to_send = latest_command 
            latest_command = None 
            
            try:
                url = f"http://{ROBOT_IP}/js?json={json.dumps(cmd_to_send)}"
                requests.get(url, timeout=0.2)
            except requests.exceptions.RequestException:
                pass 
        time.sleep(0.08) 

threading.Thread(target=network_worker, daemon=True).start()

# ==========================================
# 3. MATH & COMMAND GENERATION
# ==========================================
def send_http_command(command_dict):
    global latest_command
    latest_command = command_dict 

def send_joint_command():
    command = {
        "T": 102,
        "base": round(joints['b']['val'], 3),
        "shoulder": round(joints['s']['val'], 3),
        "elbow": round(joints['e']['val'], 3),
        "hand": round(joints['h']['val'], 3),
        "spd": 0
    }
    send_http_command(command)

def toggle_led():
    global led_state
    led_state = 255 if led_state == 0 else 0
    send_http_command({"T": 114, "led": led_state})

# ==========================================
# 4. MAIN WSL-SAFE CONTROLLER LOOP
# ==========================================
def main():
    settings = termios.tcgetattr(sys.stdin)
    
    print("\nWireless RoArm Teleop Active (WSL Anti-Lag Engine)")
    print("--------------------------------------------------")
    print("Arm (Hold): Q/E | Shoulder: W/S | Elbow: A/D")
    print("Gripper (Click): O (Open) / P (Close)")
    print("Flashlight (Click): L (Toggle)")
    print("Home Position (Click): H")
    print("CTRL-C to quit\n")

    send_joint_command()
    tty.setraw(sys.stdin.fileno())

    try:
        while True:
            # 1. Use select to check for a keypress without freezing the loop
            if select.select([sys.stdin], [], [], 0.05)[0]:
                key = sys.stdin.read(1).lower()
                
                # 2. THE MAGIC: Instantly destroy the rest of the Windows queue
                # This prevents the "run-on" target overshoot completely in WSL
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
                    joints['b']['val'] = HOME_POSITION['b']
                    joints['s']['val'] = HOME_POSITION['s']
                    joints['e']['val'] = HOME_POSITION['e']
                    joints['h']['val'] = HOME_POSITION['h']
                    send_joint_command()
                    
                elif key == 'l':
                    toggle_led()
                    
                elif key == '\x03': 
                    break

    except Exception as e:
        sys.stdout.write(f"\r\nError: {e}\r\n")
    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        print("\nDisconnected.")

if __name__ == '__main__':
    main()
