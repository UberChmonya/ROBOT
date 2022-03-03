#include <Arduino.h>
class Encoder{
    private:
    bool trig;
    byte pin1, pin2;

    public:
    int count;
    
    Encoder (byte _pin1, byte _pin2);
    void check();
};

class Motor{
    private:
    int speed, 
        wheelDiametr,
        tickPerRotation;

    byte pinPWM, 
            pinDirFoward, 
            pinDirBackward;

    bool dir;
    Encoder encoder;

    public:
    Motor(byte _pinPWM, byte _pinDirFoward,
          byte _pinDirBackward, int _wheelDiametr,
          int _tickPerRotation, Encoder &_encoder);

    void move(int8_t speed); //simple move
};