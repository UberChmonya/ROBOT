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
        Robot(uint16_t robotDiametr,uint16_t wheelDiametr,
         Motor &motorL, Motor &motorR);

        void check(void);
        void setRotate(int16_t angle);  
        void setMove(int8_t speed);    // -127 | +127
};