# WRO 2026 — R.I.S.E.

**A student robotics project developed for the World Robot Olympiad (WRO) 2026.**

R.I.S.E. is a team-built mobile robot project using the Matrix MiniR4 platform. This repository preserves the team's Arduino/C++ source code and documents the control approach, hardware overview, and known limitations.

> **Competition result:** 4th place — provincial final round, WRO 2026.

## Team

| Name | Role |
|---|---|
| Phạm Thế Vũ Lâm | Team member |
| Võ Nguyễn Đăng Nguyên | Team member |
| Nguyễn Hạnh Nguyên | Team member |
| Huỳnh Văn Tâm | Coach |

## Project at a glance

- **Controller:** Matrix MiniR4
- **Programming language:** C++ / Arduino
- **Drive system:** Differential drive with two encoder-equipped DC motors
- **Motion feedback:** Wheel encoders and IMU yaw readings
- **Additional mechanisms:** One timed DC motor actuator and two servo channels
- **Main strategy:** Scripted sequence of driving, turning, and frame-actuation commands

The source is organized into separate modules for drive motors, IMU access, robot strategy, and servo control.

## Repository structure

```text
.
├── src/
│   └── main/
│       ├── main.ino
│       ├── config.h
│       ├── drivemotor.cpp
│       ├── drivemotor.h
│       ├── imu.cpp
│       ├── imu.h
│       ├── robot.cpp
│       ├── robot.h
│       ├── servo.cpp
│       └── servo.h
├── docs/
│   ├── architecture.md
│   ├── motion-control.md
│   └── development-notes.md
├── hardware/
│   └── README.md
└── media/
    └── README.md
```

## Control approach

The drive code converts a requested travel distance into encoder degrees using the configured wheel diameter. During straight and reverse movement, it reads both wheel encoders and adjusts motor commands using a proportional term derived from the IMU yaw reading. The target speed is reduced in stages as the remaining distance decreases.

Turning routines use IMU yaw readings and support both two-wheel and one-wheel turns. The front frame actuator is controlled with fixed run times. Servo routines for the arm and gripper are present in the source; they are not called by the current `Strategy1()` sequence.

This is a description of the implementation in the archived source, not a claim of a fully autonomous or formally validated control system. In particular, the code does **not** implement a complete PID controller.

## Build and use

1. Install the Arduino IDE or another Arduino-compatible development environment.
2. Install the Matrix MiniR4 Arduino library required by the source.
3. Open `src/main/main.ino`.
4. Select the board and port appropriate for the Matrix MiniR4 setup.
5. Review the pin/motor configuration and test the robot safely before running a full strategy.

The exact library version and board package used for the competition have not yet been recorded in this repository.

## Known limitations and verification notes

- The source sets `WHEEL_DIAMETER = 6.5` cm. This value should be checked against the team's final physical calibration before reuse.
- Straight-line correction uses a proportional yaw term; it is not a complete PID implementation.
- Turning compares yaw values directly. Angle wrap-around near the -180° / +180° boundary is not explicitly handled.
- Motion loops do not currently include a timeout or encoder-stall recovery.
- The frame actuator is time-based and has no position/limit-switch feedback in this code.
- The arm/gripper routines exist, but the current scripted `Strategy1()` does not invoke them.
- No measured accuracy, repeatability, or completion-time data is included yet.

See [Motion control](docs/motion-control.md) and [Development notes](docs/development-notes.md) for more detail.

## Project status

This repository starts by preserving the source submitted by the team. Any future cleanup or refactoring should be made separately and clearly identified so the original competition version remains traceable.

## Credits

Created by Team R.I.S.E. for WRO 2026.

If you reuse this project, please credit the team and retain the context of the original competition work. No formal open-source license has been added; all rights remain with their respective owners unless the team decides otherwise.
