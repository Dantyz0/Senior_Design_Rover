# ESP-NOW Magic Bridge (Arduino)

Firmware for the USB ESP32 that sits between the laptop and the robots. This is **not** ROS 2. Flash it in Arduino IDE.

ROS 2 lives on the `main` branch. This `arduino-bridge` branch is for these sketches.

## Sketches

Open the **folder** in Arduino IDE (sketch name must match the folder).

| Sketch | Flash when | What it does |
|---|---|---|
| `ESPNOW_sketch_forriley` | Arm only (current) | Serial JSON → ESP-NOW `devCode` 1 → RoArm MAC, channel 1 |
| `ESPNOW_sketch_forriley_dual` | Arm + rover (later) | Same, plus `devCode` 2 / `2:` prefix, `ping` / `ping 2`, ACK rtt stats |

Serial: **115200**. Do not open Serial Monitor and `ros2 launch roarm_driver espnow_arm.launch.py` on the same port at once.

Dual sketch: paste the rover ESP32 MAC into `roverMacAddress` before you expect rover ACKs.

## Copy onto the laptop for Arduino IDE

These files can be copied to `C:\Arduino\` if you prefer IDE sketches outside git:

- `arduino/ESPNOW_sketch_forriley/`
- `arduino/ESPNOW_sketch_forriley_dual/`
