#include "motor.h"

Motor::Motor()
{
  pinPWM = 1;
  pinDirFoward = 1;
  pinDirBackward = 1;
  tickPerRotation = 1;

}

Motor::Motor(uint8_t _pinPWM, uint8_t _pinDirFoward,
             uint8_t _pinDirBackward,
             int _tickPerRotation)
{
    pinPWM = _pinPWM;
    pinDirFoward = _pinDirFoward;
    pinDirBackward = _pinDirBackward;
    tickPerRotation = _tickPerRotation;
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