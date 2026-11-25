# Motion control

This document explains the behavior implemented in `src/main/drivemotor.cpp` and `src/main/imu.cpp`.

## Encoder-based distance movement

For a requested distance (d), the code calculates a target wheel rotation in degrees:

```text
target_degrees = distance_cm * 360 / (wheel_diameter_cm * PI)
```

The current wheel travel estimate is calculated from the average of the absolute encoder readings from M3 and M4. The remaining distance is then used to select a speed.

## Piecewise speed schedule

`CalibrateVelocity()` selects a speed from the remaining distance:

| Remaining distance | Commanded speed |
|---:|---:|
| Greater than 55 cm | MAX_SPEED (120) |
| Greater than 30 cm | HIGH_SPEED (90) |
| Greater than 10 cm | MEDIUM_SPEED (70) |
| Greater than 5 cm | LOW_SPEED (30) |
| 5 cm or less | LOW_SPEED / 2 (15) |

The thresholds and values are configuration choices in the current source, not measured performance guarantees.

## Heading correction

During `goStraight()` and `goBack()`, the code reads IMU Euler yaw and computes:

```text
correction = Kp * yaw
```

That correction is added to the drive motor commands. This is a proportional correction term; there are no integral or derivative terms in this implementation. The source comment in `config.h` calls Kp a PID gain, but the implementation is not a complete PID controller.

## Turning

- `turn2WheelDegrees()` commands both drive motors in the same direction to rotate the robot.
- `turn1WheelDegrees()` commands one drive motor, with branches for forward/backward navigation and positive/negative requested angles.
- Both routines use IMU yaw readings and reduce commanded speed near the target angle.

The implementation compares yaw values directly. It does not explicitly normalize angular error across the -180° / +180° boundary.

## Front frame actuator

`motorFrame()` drives M1 for a fixed duration. The down and up actions use different power/time settings. There is no position sensor or limit-switch feedback in this source.

## Safety and reliability limitations

- The movement and turning loops have no timeout or stall-detection path.
- The distance estimate averages both wheel encoder readings; it does not independently regulate wheel synchronization.
- IMU yaw reset/read semantics and motor sign conventions should be verified on the physical robot before adapting the code.
- Fixed-time actuator motion can vary with battery state, load, and mechanical friction.
- Test movement routines with the robot supported or in a clear test area before running a complete mission.
