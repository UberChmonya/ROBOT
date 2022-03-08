#include "motor.h"

Motor::Motor(uint8_t _pinPWM, uint8_t _pinDirFoward,
             uint8_t _pinDirBackward,
             int _tickPerRotation, Encoder &enc)
{
    pinPWM = _pinPWM;
    pinDirFoward = _pinDirFoward;
    pinDirBackward = _pinDirBackward;
    tickPerRotation = _tickPerRotation;
    encoder = enc;
}

Motor::Motor()
{
    pinPWM = 0;
    pinDirFoward = 0;
    pinDirBackward = 0;
    tickPerRotation = 0;
    encoder = Encoder(0, 0);
}

void Motor::SetEncoder(Encoder &enc)
{
encoder = enc;
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