#include <Arduino.h>
#include "motor.h"
class Robot
{
    private:
        uint16_t robotDiametr, wheelDiametr;
        int16_t currentAngle, targetAngle,
                currentSpeed, targetSpeed,
                roundWheel, roundRobot,
                gradusWheel;

        Motor motorL, motorR;

    public:
        Robot(uint16_t robotDiametr,uint16_t _wheelDiametr);
        void setMotor(Motor &_motorL, Motor &_motorR);
        void check(void);
        void rotate(int16_t angle);  
        void move(int8_t speed);    // -127 | +127
};