#include <Arduino.h>
class Encoder{
    private:
    bool trig;
    int8_t pin1, pin2;

    public:
    int count;
    Encoder ();
    Encoder (uint8_t _pin1, uint8_t _pin2);
    void check();
};

class Motor{
    private:
    uint8_t pinPWM, 
         pinDirFoward, 
         pinDirBackward;
         
    Encoder encoder;

    public:
    int tickPerRotation, speed;
    bool dir;

    Motor (uint8_t _pinPWM, uint8_t _pinDirFoward,
          uint8_t _pinDirBackward, 
          int _tickPerRotation, Encoder &Enc);

    void setSpeed(uint8_t speed, uint8_t dir);
    void SetEncoder(Encoder &enc);
};
