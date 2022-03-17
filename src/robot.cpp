
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
    uint16_t countLBuf, countRBuf = 0;
    uint16_t speedL, speedR = 0;
   
    float dtTime, dtSpeed  = 0;
 
    uint8_t maxOut = 120;
    uint8_t minOut = 80;

    Pid pidL = Pid(Kp, Ki, Kd, minOut, maxOut);
    Pid pidR = Pid(Kp, Ki, Kd, minOut, maxOut);

    SetPoint pointL = SetPoint(20, minOut, maxOut);
    SetPoint pointR = SetPoint(20, minOut, maxOut);

    uint32_t newTimeDtL = 0;
    uint32_t oldTimeDtL = millis();
    uint32_t newTimeSpeedL = 0;
    uint32_t oldTimeSpeedL = millis();

    uint32_t newTimeDt = 0;
    uint32_t oldTimeDt = millis();


    motorR.setSpeed(100, 0);
    motorL.setSpeed(100, 0);
    while(true)
    {

        check();
        countL =  abs(motorL.encoder.count - startL);
        countR =  abs(motorR.encoder.count - startR);

        if (countLBuf != countL)
        {
            newTimeSpeed = millis();
            dtTimeL = (newTimeSpeedL - oldTimeSpeedL) / 1000.0;
            speedL =  dtTimeL;
            oldTimeSpeed = millis();
        }

        if (countRBuf != countR)
        {
            newTimeSpeedR = millis();
            dtTimeR = (newTimeSpeedR - oldTimeSpeedR) / 1000.0;
            speedR =  dtTimeR;
            oldTimeSpeedR = millis();
        }

        newTimeDt = millis();
        dtTime = (newTimeDt - oldTimeDt) / 1000.0;

        motorR.setSpeed(pidR.calculate(countR, pointR.GetSpeed(targetR, (countR * wheelDiametr) / motorR.tickPerRotation), dtTime),  1);
        motorL.setSpeed(pidL.calculate(countL, pointL.GetSpeed(targetL, (countL * wheelDiametr) / motorL.tickPerRotation), dtTime),  0);

        oldTimeDt = millis();

        Serial.print("count L is ");
        Serial.print(countL);
        Serial.print(" count R is ");
        Serial.println(countR);

        if(countR >= targetR && countR >= targetL)break;
       
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