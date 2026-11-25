#pragma once
#include <Arduino.h>

enum FrameState
{
    FRAME_UP,
    FRAME_DOWN
};
enum TurnNavigation
{
    FORWARD,
    BACKWARD
};

void MotorInit();

float CalibrateVelocity(float RemainingDistance);

void goStraight(float DISTANCE);
void goBack(float DISTANCE);
void motorFrame(FrameState state);
void turn2WheelDegrees(float ROTATE);
void turn1WheelDegrees(float ROTATE, TurnNavigation direction);
void stopMotors();
