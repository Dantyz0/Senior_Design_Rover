import serial
import json
import time

print("Connecting to RoArm via USB...")
arm_serial = serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1)
time.sleep(2) # Wait for hardware boot

# Command 401: Set Wi-Fi Boot Mode. cmd 1: AP (Hotspot) Mode
command = {"T": 401, "cmd": 1}
json_str = json.dumps(command) + '\n'

arm_serial.write(json_str.encode('utf-8'))
print(f"Sent Override: {json_str.strip()}")
print("Wi-Fi successfully reset! Please power cycle the robot.")

arm_serial.close()
