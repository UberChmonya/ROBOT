
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

void Robot::runSpeed(uint8_t speed,float deltaL,float deltaR)
{

    float vL =  PI * wheelDiametr / motorL.tickPerRotation / deltaL;
    float vR =  PI * wheelDiametr / motorR.tickPerRotation / deltaR;

    Serial.print(vL*10000, 6);
    Serial.print(',');
    Serial.println(vR*10000, 6);
    motorL.setSpeed(speed, vL, deltaL, 0);
    motorR.setSpeed(speed, vR, deltaR, 0);

}

