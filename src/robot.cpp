
#include "robot.h"

Robot::Robot(uint16_t _robotDiametr, uint16_t _wheelDiametr)
{
    robotDiametr = _robotDiametr;
    wheelDiametr = _wheelDiametr;

}

void Robot::setMotor(Motor &_motorL, Motor &_motorR)
{
    motorL = _motorL;
    motorR = _motorR;
    tickPerGradusRobotL = ((motorL.tickPerRotation * robotDiametr) / wheelDiametr) / 360.0;
    tickPerGradusRobotR = ((motorR.tickPerRotation * robotDiametr) / wheelDiametr) / 360.0;
    tickPerGradusWheelL = motorL.tickPerRotation / 360;
    tickPerGradusWheelR = motorR.tickPerRotation / 360;
}

void Robot::stopMotors(void)
{
    motorL.stop();
    motorR.stop();
}

void Robot::runSpeed(uint8_t speed, uint32_t deltaL, uint32_t deltaR)
{

    float vL =  PI * wheelDiametr / deltaL;
    float vR =  PI * wheelDiametr / deltaR;
    motorL.setSpeed(speed, 0, vL);
    motorR.setSpeed(speed, 0, vR);

}

