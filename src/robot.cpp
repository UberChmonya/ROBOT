#include<robot.h>

Robot::Robot(uint16_t _robotDiametr, uint16_t _wheelDiametr)
{
    uint16_t robotDiametr = _robotDiametr;
    uint16_t wheelDiametr = _wheelDiametr;
    roundWheel = PI * wheelDiametr;
    roundRobot = PI * robotDiametr;
    gradusWheel = 360 / roundRobot / roundWheel;
}
void Robot::setMotor(Motor &_motorL, Motor &_motorR)
{
    motorL = _motorL;
    motorR = _motorR;
}

void Robot::check()
{
    motorL.encoder.check();
    motorR.encoder.check();
}

void Robot::rotate(int16_t angle)
{   
    uint16_t startL = motorL.encoder.count;
    uint16_t startR = motorR.encoder.count;
    uint16_t gradusL = 0;
    uint16_t gradusR = 0;
    while(true)
    {
        check();
        gradusL = gradusWheel * (motorL.encoder.count - startL/ motorL.tickPerRotation);
        gradusR = gradusWheel * (motorR.encoder.count - startR/ motorR.tickPerRotation);

    }

}