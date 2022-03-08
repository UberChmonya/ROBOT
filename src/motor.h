#include <Arduino.h>
#include "encoder.h"



class Motor{
    private:
    uint8_t pinPWM, 
         pinDirFoward, 
         pinDirBackward;
         
    public:
    Encoder encoder;
    int tickPerRotation, speed;
    bool dir;
    Motor();  
    Motor (uint8_t _pinPWM, uint8_t _pinDirFoward,
          uint8_t _pinDirBackward, 
          int _tickPerRotation, Encoder &Enc);

    void setSpeed(uint8_t speed, uint8_t dir);
    void SetEncoder(Encoder &enc);
};
