#include "robot.h"
#include <Arduino.h>
Encoder::Encoder(byte _pin1, byte _pin2)
{
  pin1 = _pin1;
  pin2 = _pin2;
  trig = 0;
  count = 0;
}

void Encoder::check()
{
  if ((digitalRead(pin1) == 1) & (trig == 0))
  {
    trig = 1;
    if(digitalRead(pin2) == 1)count++;
    else count--;
  }

  if((digitalRead(pin1) == 0) & (trig == 1))
  {
    trig = 1;
  }
}

Motor::Motor(byte _pinPWM, byte _pinDirFoward,
          byte _pinDirBackward, int _wheelDiametr,
          int _tickPerRotation, Encoder &_encoder)
{
byte pinPWM = _pinPWM;
byte pinDirFoward = _pinDirFoward;
byte pinDirBackward = _pinDirBackward;
int  wheelDiametr = _wheelDiametr;
int  tickPerRotation = _tickPerRotation;
Encoder encoder = &_encoder;

}