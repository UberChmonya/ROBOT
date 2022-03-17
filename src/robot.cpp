
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

void Robot::check(void)
{
    motorL.encoder.check();
    motorR.encoder.check();
}

void Robot::stopMotors(void)
{
    motorL.stop();
    motorR.stop();
}

void setPid(Pid &_pidWheelL,Pid &pidWheelR)
{
    pidWheelR = _pidWheelR;
    pidWheelL = _pidWheelL;
}

void Robot::runSpeed(unt8_t speed, uint32_t deltaL, uint32_t deltaR)
{

    vL =  PI * wheelDiametr / deltaL;
    vR =  PI * wheelDiametr / deltaR;
    motorL.setSpeed());
    motorR.setSpeed();

}


/*
void Robot::rotate(int16_t angle)
{   
    motorL.stop();
    motorR.stop();
    delay(100);
    uint16_t startL = motorL.encoder.count;
    uint16_t startR = motorR.encoder.count;



       
    
    stopMotors();
}

void Robot::move(uint16_t distanse)
{   
    motorL.stop();
    motorR.stop();
    delay(100);
    uint16_t startL = motorL.encoder.count;
    uint16_t startR = motorR.encoder.count;
    int16_t target = distanse / wheelDiametr * motorR.tickPerRotation;
 
}
*/