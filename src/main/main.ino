#include "MatrixMiniR4.h"
#include "robot.h"
#include "imu.h"

void setup()
{
  MiniR4.begin();
  MiniR4.PWR.setBattCell(2);
  Serial.begin(9600);
  delay(2000);
  robotInit();
  IMU_Init();
}

void loop()
{
  ///StrategyTest();
  Strategy1();
  while (true)
  {
    delay(500);
  }
}
