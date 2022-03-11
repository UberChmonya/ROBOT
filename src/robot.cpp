
#include "robot.h"
#include "SetPoint.h"
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

void Robot::setCoef(float _Kp,float _Ki, float _Kd)
{

    Kp = _Kp;
    Ki = _Ki;
    Kd = _Kd;


}


void Robot::rotate(int16_t angle)
{   
    motorL.stop();
    motorR.stop();
    delay(100);
    uint16_t startL = motorL.encoder.count;
    uint16_t startR = motorR.encoder.count;

    uint16_t targetL = (wheelDiametr * tickPerGradusRobotL * angle) / motorL.tickPerRotation;
    uint16_t targetR = (wheelDiametr * tickPerGradusRobotR * angle) / motorR.tickPerRotation;

    uint16_t countL, countR = 0;
    uint32_t newTime = 0;
    float dt = 0;
    uint32_t oldTime = millis();
 
    uint8_t maxOut = 120;
    uint8_t minOut = 80;
    Pid pidL = Pid(Kp, Ki, Kd, minOut, maxOut);
    Pid pidR = Pid(Kp, Ki, Kd, minOut, maxOut);
    SetPoint pointL = SetPoint(20, 70, 120);
    SetPoint pointR = SetPoint(20, 70, 120);
    motorR.setSpeed(100, 0);
    motorL.setSpeed(100, 0);

    while(true)
    {

        check();
        countL =  abs(motorL.encoder.count - startL);
        countR =  abs(motorR.encoder.count - startR);
        newTime = millis();
        dt = (newTime - oldTime) / 1000.0;

        motorR.setSpeed(pidR.calculate(countR, pointR.GetSpeed(targetR, (countR * wheelDiametr) / motorR.tickPerRotation), dt),  1);
        motorL.setSpeed(pidL.calculate(countL, pointL.GetSpeed(targetL, (countL * wheelDiametr) / motorL.tickPerRotation), dt),  0);

        oldTime = millis();
        if(targetR >= countR && targetL >= countR)break;
        Serial.println((countL * wheelDiametr) / motorL.tickPerRotation);
    }
    stopMotors();
}
/*
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