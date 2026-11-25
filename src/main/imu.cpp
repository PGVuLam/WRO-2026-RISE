#include "imu.h"
#include "MatrixMiniR4.h"

void IMU_Init(){
    MiniR4.Motion.resetIMUValues();
}

float Read_Print_Anggle() {
    return MiniR4.Motion.getEuler(MiniR4Motion::AxisType::Yaw);
}
