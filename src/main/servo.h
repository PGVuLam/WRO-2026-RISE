#pragma once
#include <Arduino.h>

enum ServoState
{
  Open,
  Close,
  High,
  Medium,
  Low
};

void ServoInit();
void GripperControl(ServoState state); // Open and Close Gripper
void ArmControl(ServoState position); // Up and Down Arm
