#include "robot.h"
Encoder::Encoder(uint8_t _pin1, uint8_t _pin2)
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
    if (digitalRead(pin2) == 1)
      count++;
    else
      count--;
  }

  if ((digitalRead(pin1) == 0) & (trig == 1))
  {
    trig = 0;
  }
}

Motor::Motor(uint8_t _pinPWM, uint8_t _pinDirFoward,
             uint8_t _pinDirBackward,
             int _tickPerRotation, Encoder &enc)
{
  uint8_t pinPWM = _pinPWM;
  uint8_t pinDirFoward = _pinDirFoward;
  uint8_t pinDirBackward = _pinDirBackward;
  int     tickPerRotation = _tickPerRotation;
  Encoder encoder = enc;
}

void Motor::setSpeed(uint8_t speed, uint8_t dir)
{
  analogWrite(pinPWM, speed);
  if (dir == 0)
  {
    digitalWrite(pinDirBackward, 0);
    digitalWrite(pinDirFoward, 1);
  }
  else
  {
    digitalWrite(pinDirBackward, 1);
    digitalWrite(pinDirFoward, 0);
  }
}