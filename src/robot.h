#pragma once
#include <Arduino.h>
#include "motor.h"
#include "PID.h"
#include "SetPoint.h"
class Robot
{
    private:
        uint16_t robotDiametr, wheelDiametr;
        int16_t currentAngle, targetAngle,
                currentSpeed, targetSpeed;

        float tickPerGradusRobotL, tickPerGradusRobotR;
        float tickPerGradusWheelL, tickPerGradusWheelR;
        float Kp, Ki, Kd;

    public:
        Motor motorL, motorR;
        Robot(uint16_t robotDiametr,uint16_t _wheelDiametr);
        void setMotor(Motor &_motorL, Motor &_motorR);

        void check(void);
        void stopMotors(void);
        void setCoef(float kP,float kI,float kD);

        void rotate(int16_t angle);  
       // void move(uint16_t distanse);    
};