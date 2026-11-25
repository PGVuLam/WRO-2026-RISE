#include "servo.h"
#include "MatrixMiniR4.h"
#include "config.h"

ServoState ArmPosition;

void ServoInit(){
  MiniR4.RC1.setHWDir(false);
  MiniR4.RC2.setHWDir(false);
  MiniR4.RC1.setAngle(ARM_HIGH);
  GripperControl(Open);
  ArmPosition = High;
}

void GripperControl(ServoState state) {
  if (state == Close) {
    MiniR4.RC2.setAngle(GRIPPER_CLOSE);
  }
  if (state == Open) {
    MiniR4.RC2.setAngle(GRIPPER_OPEN);
  }
  if (state == Medium){
    MiniR4.RC2.setAngle(GRIPPER_MEDIUM);
  }
}

void ArmControl(ServoState position) {
  if (position == High) {
    MiniR4.RC1.setAngle(ARM_HIGH);
    ArmPosition = High;
  }
  if (position == Low) {
    int CurrentAngle;
    if (ArmPosition == High)
    {
      CurrentAngle = ARM_HIGH;
    }
    else if (ArmPosition = Medium) {
      CurrentAngle = ARM_MEDIUM;
    }
    while (CurrentAngle >= ARM_LOW) {
        MiniR4.RC1.setAngle(CurrentAngle);
        delay(50);
        CurrentAngle -= 5;
    }
    ArmPosition = Low;
  }
  if (position == Medium) {
    MiniR4.RC1.setAngle(ARM_MEDIUM);
    ArmPosition = Medium;
  }
}
