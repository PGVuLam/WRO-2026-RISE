#pragma once

// ===== Wheel Specifications =====
const float WHEEL_DIAMETER = 6.5;  // in cm

// ===== Motor Motion =====
const int MAX_SPEED = 120;
const int HIGH_SPEED = 90;
const int MEDIUM_SPEED = 70;
const int LOW_SPEED = 30;
const float Kp = 1.6;  // Proportional gain for PID control
const float DRIVE_TURN = 30;

// ===== Frame Motion =====
const int FRAME_SPEED = 40;
const int FRAME_MOVE_TIME = 900;

// ===== Servo Angle =====
// Gripper Servo
const int GRIPPER_OPEN = 7;
const int GRIPPER_MEDIUM = 20;
const int GRIPPER_CLOSE = 80;  //calibrate this parameter to increase or reduce gripping force

// ===== Arm Servo =====
const int ARM_HIGH = 170;
const int ARM_MEDIUM = 100;  // before is Up
const int ARM_LOW = 30;      // before is Down
