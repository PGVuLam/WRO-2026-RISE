# Software architecture

The firmware is divided into small modules so that the robot's startup, movement, sensing, mechanisms, and mission sequence are easier to locate.

## Module map

| File | Responsibility |
|---|---|
| `main.ino` | Arduino entry points: initialize the MiniR4, robot, and IMU; execute `Strategy1()` once |
| `config.h` | Wheel diameter, speed levels, proportional gain, frame timing, and servo angles |
| `drivemotor.h/.cpp` | Motor initialization, straight/reverse movement, turns, frame actuation, and stopping |
| `imu.h/.cpp` | Reset IMU values and read Euler yaw |
| `robot.h/.cpp` | Robot initialization and scripted mission strategies |
| `servo.h/.cpp` | Arm and gripper servo routines |

## Runtime flow

1. `setup()` starts the MiniR4, configures the battery cell count, starts Serial, and waits briefly.
2. `robotInit()` initializes the encoder motors and servo channels.
3. The IMU values are reset.
4. `loop()` executes `Strategy1()`, then remains in a delay loop so the mission is not restarted.

## Control and actuator channels

The source addresses drive motors M3 and M4, the frame motor M1, and servo channels RC1 and RC2. The two drive motors are treated as opposite-side motors, so the commanded signs differ for straight forward and reverse movement.

## Scope

This document describes the files and calls present in the archived source. It does not assert that every declared function is used by the active mission. In particular, `Strategy1()` invokes the drive and frame routines, but does not call `ArmControl()` or `GripperControl()` directly.
