# Development notes and review checklist

This file records issues visible in the archived source. The competition source is preserved as-is; these notes do not silently patch it.

## Items to verify before reuse

1. **Wheel diameter:** the team has confirmed that the project documentation should follow the competition source value, `WHEEL_DIAMETER = 6.5` cm. Keep this value unless the team later supplies a revised calibration.
2. **Servo arm state condition:** in `servo.cpp`, the branch `else if (ArmPosition = Medium)` assigns `Medium` rather than comparing the current state. This is likely a logic bug.
3. **Servo arm angle initialization:** `CurrentAngle` is assigned only when `ArmPosition` is High or the Medium branch is taken. Add a defined fallback before reusing this routine.
4. **Yaw wrap-around:** turning loops compare raw Euler yaw values and do not handle the transition between +180° and -180°.
5. **Timeouts:** add bounded execution time and fault handling to encoder and yaw loops before deploying on unattended hardware.
6. **Strategy organization:** `Strategy1()` is a long linear sequence. Future refactoring could split it into named mission stages while keeping a copy of the original competition sequence.
7. **Naming and comments:** `Read_Print_Anggle()` contains a spelling inconsistency, and the Kp comment says PID even though only a proportional term is implemented.

## Source preservation policy

The files under `src/main/` represent the submitted source snapshot. If improvements are made later, keep the original snapshot available and describe the changes in commits or a separate branch. Hardware behavior should be validated before treating a code review observation as a confirmed field failure.
