#include "drivemotor.h"
#include "MatrixMiniR4.h"
#include "config.h"
#include "imu.h"
#include "cmath"

void MotorInit() {
  MiniR4.M3.resetCounter();
  MiniR4.M4.resetCounter();
  MiniR4.M3.setPPR_RPM(545, MAX_SPEED);
  MiniR4.M4.setPPR_RPM(545, MAX_SPEED);
}

float CalibrateVelocity(float RemainingDistance) {
  if (RemainingDistance > 55) {
    return MAX_SPEED;
  }
  else if (RemainingDistance > 30) {
    return HIGH_SPEED;
  }
  else if (RemainingDistance > 10) {
    return MEDIUM_SPEED;
  }
  else if (RemainingDistance > 5) {
    return LOW_SPEED;
  }
  return LOW_SPEED/2;
}

void goStraight(float DISTANCE) {
  IMU_Init();
  MiniR4.M3.resetCounter();
  MiniR4.M4.resetCounter();
  float DEGREES = DISTANCE * 360/(WHEEL_DIAMETER*PI);
  MiniR4.M3.setSpeed(MAX_SPEED);
  MiniR4.M4.setSpeed(-MAX_SPEED);
  while (!(fabs(MiniR4.M3.getDegrees()) >= DEGREES && fabs(MiniR4.M4.getDegrees()) >= DEGREES)) {
    float RemainingDistance = DISTANCE - (fabs(MiniR4.M3.getDegrees()) + fabs(MiniR4.M4.getDegrees()))/2 * WHEEL_DIAMETER * PI / 360;
    float velocity = CalibrateVelocity(RemainingDistance);
    float correction = Kp * Read_Print_Anggle();
    MiniR4.M3.setSpeed(velocity + correction);
    MiniR4.M4.setSpeed(-velocity + correction);
    if (RemainingDistance < 0.2) {
      break;
    }
  }
  stopMotors();
}

void goBack(float DISTANCE) {
  IMU_Init();
  MiniR4.M3.resetCounter();
  MiniR4.M4.resetCounter();
  float DEGREES = DISTANCE * 360/(WHEEL_DIAMETER*PI);
  MiniR4.M3.setSpeed(-MAX_SPEED);
  MiniR4.M4.setSpeed(MAX_SPEED);
  while (!(fabs(MiniR4.M3.getDegrees()) >= DEGREES && fabs(MiniR4.M4.getDegrees()) >= DEGREES)) {
    float RemainingDistance = DISTANCE - (fabs(MiniR4.M3.getDegrees()) + fabs(MiniR4.M4.getDegrees()))/2 * WHEEL_DIAMETER * PI / 360;
    float velocity = CalibrateVelocity(RemainingDistance);
    float correction = Kp * Read_Print_Anggle();
    MiniR4.M3.setSpeed(-velocity + correction);
    MiniR4.M4.setSpeed(velocity + correction);
    if (RemainingDistance < 0.3) {
      break;
    }
  }
  stopMotors();
}

void motorFrame(FrameState state) {
  if (state == FRAME_DOWN) {
    MiniR4.M1.setPower(FRAME_SPEED);
    delay(FRAME_MOVE_TIME);
  }
  else if (state == FRAME_UP) {
    MiniR4.M1.setPower(-FRAME_SPEED-20);
    delay(FRAME_MOVE_TIME-400);
  }
  MiniR4.M1.setPower(0);
  MiniR4.M1.setBrake(true);
}

void turn2WheelDegrees(float ROTATE) {
  IMU_Init();
  if (ROTATE > 0) {
    MiniR4.M4.setSpeed(-DRIVE_TURN);
    MiniR4.M3.setSpeed(-DRIVE_TURN);
    while (Read_Print_Anggle() < ROTATE) {
      if ((ROTATE - Read_Print_Anggle())/ROTATE < 0.4) {
        MiniR4.M4.setSpeed(-DRIVE_TURN/2);
        MiniR4.M3.setSpeed(-DRIVE_TURN/2);
      }
    }
  }
  else if (ROTATE < 0) {
    MiniR4.M4.setSpeed(DRIVE_TURN);
    MiniR4.M3.setSpeed(DRIVE_TURN);
    while (Read_Print_Anggle() > ROTATE) {
      if ((ROTATE - Read_Print_Anggle())/ROTATE < 0.4) {
        MiniR4.M4.setSpeed(DRIVE_TURN/2);
        MiniR4.M3.setSpeed(DRIVE_TURN/2);
      }
    }
  }
  stopMotors();
}

void turn1WheelDegrees(float ROTATE, TurnNavigation direction) {
  IMU_Init();
  if (ROTATE > 0 && direction == FORWARD) {
    MiniR4.M4.setSpeed(-DRIVE_TURN);
    while (Read_Print_Anggle() < ROTATE) {
      if ((ROTATE - Read_Print_Anggle())/ROTATE < 0.4) {
        MiniR4.M4.setSpeed(-DRIVE_TURN/2);
      }
    }
  }
  else if (ROTATE < 0 && direction == FORWARD) {
    MiniR4.M3.setSpeed(DRIVE_TURN);
    while (Read_Print_Anggle() > ROTATE) {
      if ((ROTATE - Read_Print_Anggle())/ROTATE < 0.4) {
        MiniR4.M3.setSpeed(DRIVE_TURN/2);
      }
    }
  }
  else if (ROTATE > 0 && direction == BACKWARD) {
    MiniR4.M4.setSpeed(DRIVE_TURN);
    while (fabs(Read_Print_Anggle()) < ROTATE) {
      if ((ROTATE - fabs(Read_Print_Anggle()))/ROTATE < 0.4) {
        MiniR4.M4.setSpeed(DRIVE_TURN/2);
      }
    }
  }
  else if (ROTATE < 0 && direction == BACKWARD) {
    MiniR4.M3.setSpeed(-DRIVE_TURN);
    while (Read_Print_Anggle() < fabs(ROTATE)) {
      if ((fabs(ROTATE) - Read_Print_Anggle())/fabs(ROTATE) < 0.4) {
        MiniR4.M3.setSpeed(-DRIVE_TURN/2);
      }
    }
  }
  stopMotors();
}

void stopMotors() {
  MiniR4.M3.setBrake(true);
  MiniR4.M4.setBrake(true);
  MiniR4.M3.setSpeed(0);
  MiniR4.M4.setSpeed(0);
  delay(10);
}
