
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
    int16_t target = tickPerGradusRobotR * angle;
    int16_t countL, countR = 0;
    uint32_t newTime = 0;
    float dt = 0;
    uint32_t oldTime = millis();
    uint8_t speedR = 100;
    uint8_t speedL = 100;
    uint8_t maxOut = 120;
    uint8_t minOut = 80;
    float err = 0;
    float D = 0;
    motorR.setSpeed(speedR, 0);

    while(true)
    {
        if(target <= countR)break;
        check();
        countL =  abs(motorL.encoder.count - startL);
        countR =  abs(motorR.encoder.count - startR);
        newTime = millis();
        dt = (newTime - oldTime) / 1000.0;

        err = countR - countL;
        static float integral = 0, prevErr = 0;
        integral = integral + (float)err * dt * Ki;
        if ( integral < minOut ) integral = minOut;
        if ( integral > maxOut ) integral = maxOut;

        D = (err - prevErr) / dt;
        prevErr = err;
        speedL = err * Kp + integral + D * Kd;
//        if ( speedL < minOut ) speedL = minOut;
        speedL = ( speedL < minOut ) ? minOut : speedL;
        //constrain(speedL , 80, 120);
        if ( speedL > maxOut ) speedL = maxOut;


        oldTime = millis();
        Serial.println(speedL);
        motorL.setSpeed(speedL, 1);
    }
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
    int16_t countL, countR = 0;
    uint32_t newTime = 0;
    float dt = 0;
    uint32_t oldTime = millis();
    uint8_t speedR = 100;
    uint8_t speedL = 100;
    uint8_t maxOut = 120;
    uint8_t minOut = 80;
    float err = 0;
    float D = 0;
    motorR.setSpeed(speedR, 1);

    while(true)
    {
        if(target <= countR)break;
        check();
        countL =  motorL.encoder.count - startL;
        countR =  motorR.encoder.count - startR;
        newTime = millis();
        dt = (newTime - oldTime) / 1000.0;

        err = countR - countL;
        static float integral = 0, prevErr = 0;
        integral = constrain(integral + (float)err * dt * Ki, minOut, maxOut);
        D = (err - prevErr) / dt;
        prevErr = err;
        speedL = constrain(err * Kp + integral + D * Kd, minOut, maxOut);


        oldTime = millis();
        Serial.print("right- ");
        Serial.print(countR);
        Serial.print(" left- ");
        Serial.println(countL);
        motorL.setSpeed(speedL, 1);
    }
    stopMotors();
}
