#include "robot.h"
#include "drivemotor.h"
#include "servo.h"
#include "config.h"
#include "imu.h"
#include "MatrixMiniR4.h"

void robotInit() {
  MotorInit();
  Read_Print_Anggle();
  ServoInit();
}

void Strategy1() {
  //Stage 1: Complete 3 basic pieces mission;
  turn2WheelDegrees(-90);
  goStraight(100.8);
  turn2WheelDegrees(90);
  goBack(3.7);
  motorFrame(FRAME_DOWN);
  motorFrame(FRAME_UP);
  turn2WheelDegrees(5);
  motorFrame(FRAME_DOWN);
  turn2WheelDegrees(-5);
  goBack(3);
  turn1WheelDegrees(-11, BACKWARD);
  turn1WheelDegrees(45, FORWARD);
  goStraight(13);
  turn1WheelDegrees(5, FORWARD);
  goStraight(6);
  turn1WheelDegrees(5, FORWARD);
  goStraight(6);
  turn1WheelDegrees(-50, BACKWARD);
  goBack(6.3);
  turn1WheelDegrees(32, BACKWARD);
  goBack(83.5);
  turn1WheelDegrees(90, FORWARD);
  goStraight(10);
  motorFrame(FRAME_UP);
  goBack(45);
  goStraight(16);
  turn1WheelDegrees(90, FORWARD);
  goStraight(14);
  turn2WheelDegrees(90);
  goBack(1);
  motorFrame(FRAME_DOWN);
  goBack(1);
  turn2WheelDegrees(89);
  turn1WheelDegrees(-25, FORWARD);
  goStraight(16.5);
  turn1WheelDegrees(24.2, FORWARD);
  goStraight(170);
  goBack(9);
  motorFrame(FRAME_UP);

  //Stage 2: Complete ciment mission
  turn2WheelDegrees(-90);// White Ciment
  goStraight(3.5);
  turn2WheelDegrees(-90);
  goStraight(100);
  turn2WheelDegrees(28);
  goStraight(15);
  turn2WheelDegrees(-27);
  goStraight(59);
  motorFrame(FRAME_DOWN);
  goStraight(10);
  goBack(24);
  turn2WheelDegrees(-90);
  goBack(40);
  goStraight(40.5);
  turn2WheelDegrees(-60);
  turn2WheelDegrees(5);
  goStraight(13);
  delay(300);
  goStraight(13);
  delay(300);
  goStraight(13);
  delay(300);
  motorFrame(FRAME_UP);
  goBack(22);
  motorFrame(FRAME_DOWN);
  goStraight(24);
  motorFrame(FRAME_UP);
  goBack(6);
  turn2WheelDegrees(-38); //Green Ciment
  turn2WheelDegrees(90);
  goStraight(3);
  turn2WheelDegrees(90);
  goStraight(40);
  motorFrame(FRAME_DOWN);
  goStraight(20);
  goBack(19);
  turn2WheelDegrees(-90);
  turn2WheelDegrees(-90);
  goStraight(38.5);
  motorFrame(FRAME_UP);
  goBack(90);
  goStraight(2);
  turn1WheelDegrees(90, FORWARD); //Yellow Ciment
  goStraight(4);
  motorFrame(FRAME_DOWN);
  goStraight(20);
  goBack(5);
  turn2WheelDegrees(-90);
  goStraight(38.5);
  turn2WheelDegrees(-90);
  goStraight(53);
  turn1WheelDegrees(90, FORWARD);
  goStraight(52);
  turn2WheelDegrees(90);
  goStraight(8);
  motorFrame(FRAME_UP);
  goBack(9);
  turn2WheelDegrees(89.5);
  goStraight(65);
  turn1WheelDegrees(-45, FORWARD);
  goStraight(17);
  motorFrame(FRAME_DOWN);
  goBack(22);
  turn1WheelDegrees(-45, BACKWARD);
  goBack(140);
  turn2WheelDegrees(-90);
  goStraight(44);
  turn2WheelDegrees(90);
  goStraight(32);
}

void Strategy2() {
}

void Strategy3() {
}

void StrategyTest() {
  goStraight(150);
  goBack(100);
}
