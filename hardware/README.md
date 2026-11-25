# Hardware overview

The archived firmware targets the Matrix MiniR4 platform.

## Interfaces referenced by the source

| Interface | Use in source |
|---|---|
| M3, M4 | Differential-drive motors with encoder counters |
| M1 | Front frame actuator, driven by timed power commands |
| RC1 | Arm servo |
| RC2 | Gripper servo |
| Motion IMU | Euler yaw reading for heading correction and turning |

The source configures M3 and M4 with `setPPR_RPM(545, MAX_SPEED)`. Record the exact motor model, gear ratio, wheel specification, wiring, and MiniR4 library version here only after confirming them against the team's hardware.

## Hardware documentation still needed

- Robot overview photographs
- Wiring / port assignment diagram
- Mechanical frame and attachment drawings
- Exact motor and servo part numbers
- Final wheel diameter measurement and calibration procedure
- Battery configuration and operating notes

Do not infer a wiring diagram or component specification from software port names alone.
