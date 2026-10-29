# ESP-NOW Magic Bridge (ESP32)

Firmware for the USB ESP32 that sits between the laptop and the robots. This is **not** ROS 2. Flash it in Arduino IDE.

ROS 2 lives on the `main` branch. This `ESPNOW_bridge` branch is for these sketches.

Sketches are in `ESP32_code/`. Open the **folder** in Arduino IDE (sketch name must match the folder).

| Sketch | Flash when | What it does |
|---|---|---|
| `ESPNOW_sketch_forriley` | Arm only (current) | Serial JSON → ESP-NOW `devCode` 1 → RoArm MAC, channel 1 |
| `ESPNOW_sketch_forriley_dual` | Arm + rover (later) | Same, plus `devCode` 2 / `2:` prefix, `ping` / `ping 2`, ACK rtt stats |

Serial: **115200**. Do not open Serial Monitor and `ros2 launch roarm_driver espnow_arm.launch.py` on the same port at once.

Dual sketch: paste the rover ESP32 MAC into `roverMacAddress` before you expect rover ACKs.

## Copy onto the laptop for Arduino IDE

If you prefer sketches outside git, copy to `C:\Arduino\`:

- `ESP32_code/ESPNOW_sketch_forriley/`
- `ESP32_code/ESPNOW_sketch_forriley_dual/`
