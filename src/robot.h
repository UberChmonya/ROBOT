#pragma once
#include <Arduino.h>
#include "motor.h"
#include "SetPoint.h"

class Robot
{
    private:
        
        int16_t currentAngle, targetAngle,
                currentSpeed, targetSpeed;

        float tickPerGradusRobotL, tickPerGradusRobotR;
        float tickPerGradusWheelL, tickPerGradusWheelR;
        float Kp, Ki, Kd;

    public:
    uint16_t robotDiametr, wheelDiametr;
        Motor motorL, motorR;
    
        Robot(uint16_t robotDiametr,uint16_t _wheelDiametr);
        void setMotor(Motor &_motorL, Motor &_motorR);

        void runSpeed(uint8_t speed,uint32_t deltaL,uint32_t deltaR);
        void stopMotors(void);

        void rotate(int16_t angle);  
       // void move(uint16_t distanse);    
};