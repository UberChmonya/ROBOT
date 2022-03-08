#include <Arduino.h>
#include "encoder.h"


class Motor{
    private:
    uint8_t pinPWM, 
         pinDirFoward, 
         pinDirBackward;
         
    public:
    Encoder encoder;
    uint16_t tickPerRotation;
    int16_t speed;
    bool dir;
    
    Motor(); // dont use!!!!
    Motor (uint8_t _pinPWM, uint8_t _pinDirFoward,
          uint8_t _pinDirBackward, int16_t _tickPerRotation);

    void SetEncoder(Encoder &enc);
    void setSpeed(uint8_t speed, uint8_t dir);

};
