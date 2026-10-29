# Duck Catcher Rover

Senior design ROS 2 workspace for a mobile rover that drives to GPS-tagged ducks, picks them up with a RoArm manipulator, dumps the load, and returns home.

**Repo:** [Dantyz0/Senior_Design_Rover](https://github.com/Dantyz0/Senior_Design_Rover)

## Mission

1. Receive a duck GPS coordinate (drone / spotter handoff on `/drone_gps`).
2. Drive autonomously. Slow at **10 ft**, stop at **1 ft**.
3. Halt the base. **Manual arm teleop** to grab the duck and put it in the dump bed.
4. Repeat for **3 ducks**.
5. Drive to drop-off and pulse the dump-bed solenoid (`/dump_bed`).
6. Return to home and end.

Autonomy owns driving. Grasping is operator-in-the-loop.

## Hardware (current)

| Piece | Status | Comms |
|---|---|---|
| Waveshare RoArm-M2 | Working | ESP-NOW via USB “Magic Bridge” ESP32, `devCode` 1 |
| Rover (front hoverboard drive, rear casters) | Not in hand yet | Same bridge, `devCode` 2, **channel 1** (do not split channels) |
| Dump solenoid | Planned on rover ESP | `devCode` 2 JSON in the ESP-NOW `message` field |
| GPS | Modules TBD | Likely rover ESP → ESP-NOW → laptop → `NavSatFix` |

Laptop talks USB serial to **one** bridge ESP32. That board ESP-NOW’s to the arm and (later) the rover. Both radios stay on **Wi-Fi channel 1** to match the arm hotspot. Devices are split by **MAC + `devCode`**, not by channel.

Arduino firmware is **not** in this git repo. It lives on the laptop, e.g.:

- Arm-only (what you flash today): `C:\Arduino\ESPNOW_sketch_forriley\`
- Dual arm+rover+ping/ACK (when the rover exists): `C:\Arduino\ESPNOW_sketch_forriley_dual\`

Do not open Serial Monitor and the ROS bridge on the same `/dev/ttyUSB0` at the same time.

## Workspace packages

```
src/
  mission_control/       GPS → ENU, mission state machine, fake GPS for sim
  rover_description/     URDF + Gazebo (diff-drive, front wheels, rear casters, arm mount)
  rover_moveit_config/   MoveIt 2 for the arm
  roarm_description/     RoArm M2/M3 meshes and xacro
  roarm_driver/          ESP-NOW ROS bridge + keyboard teleop
  roarm_msgs/            Arm services/messages
```

Gazebo `x` = east, `y` = north. Spawn at the origin is “home GPS.”

## Setup

ROS 2 **Lyrical** (or the distro this machine is built against), `colcon`, Gazebo (Harmonic/Ionic stack used by `ros_gz_sim`), Python `pyserial`.

On **WSL2**, Fast DDS discovery between two terminals often fails. Use Cyclone DDS (already proven for this project):

```bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```

Put that in `~/.bashrc` so every terminal gets it.

```bash
cd ~/duckcatcher_ws
source /opt/ros/lyrical/setup.bash   # or your distro
colcon build --symlink-install
source install/setup.bash
```

`build/`, `install/`, and `log/` are gitignored. Do not commit them.

## Run: real arm (ESP-NOW)

Bridge ESP flashed with the **arm-only** sketch, plugged in as `/dev/ttyUSB0`.

```bash
source ~/duckcatcher_ws/install/setup.bash
ros2 launch roarm_driver espnow_arm.launch.py
```

That starts the serial bridge **and** keyboard teleop in one terminal. Click that terminal, then:

| Keys | Action |
|---|---|
| Q / E | Base |
| W / S | Shoulder |
| A / D | Elbow |
| O / P | Gripper open / close |
| H | Home |
| L | LED |

Ctrl+C stops both nodes.

Bridge only (no keys):

```bash
ros2 launch roarm_driver espnow_arm.launch.py start_teleop:=false
```

Wrong port: `serial_port:=/dev/ttyUSB1`.

ROS topics: `/espnow/joint_command`, `/espnow/led`, `/joint_states`.

## Run: Gazebo mission (no rover hardware)

**Terminal 1 — sim**

```bash
source ~/duckcatcher_ws/install/setup.bash
ros2 launch rover_description gazebo.launch.py
```

**Terminal 2 — mission** (this is the one that takes **Enter** after a pickup)

```bash
source ~/duckcatcher_ws/install/setup.bash
ros2 launch mission_control mission.launch.py
```

**Terminal 3 — fake duck GPS** (8 m east of home, should drive +X)

```bash
source ~/duckcatcher_ws/install/setup.bash
ros2 run mission_control fake_gps --ros-args -p east_m:=8.0 -p north_m:=0.0
```

When the rover stops (~1 ft), click the **mission** terminal and press **Enter**. Then publish the next duck, e.g.:

```bash
ros2 run mission_control fake_gps --ros-args -p east_m:=4.0 -p north_m:=6.0
ros2 run mission_control fake_gps --ros-args -p east_m:=-3.0 -p north_m:=5.0
```

After the third Enter: drop-off at `(6, 4)` m, `/dump_bed` pulse, return home.

Home GPS origin (Salina field default) is in `src/mission_control/config/mission.yaml`.

## Git

Sync source only:

```bash
git add -A
git status          # should not list build/, install/, log/
git commit -m "Your message"
git push
```

`git add -A` stages new files, edits, **and** deletions of tracked files. Ignored folders stay local.

## Later (rover hardware)

Same USB bridge, `devCode` 2, rover MAC, channel 1. ROS will still publish `/cmd_vel` and need `/odom` (rover GPS/IMU, not Gazebo). Duck GPS stays on `/drone_gps`; rover pose is a second stream. Firmware for that is the dual Arduino sketch, not this repo.

## Maintainers

Daniel Moran (`dlmoran@ksu.edu`) — KSU Salina senior design.
