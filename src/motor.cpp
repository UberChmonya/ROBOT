#include "motor.h"

Motor::Motor(){} // dont use!!!!

Motor::Motor(uint8_t _pinPWM, uint8_t _pinDirFoward, uint8_t _pinDirBackward, int _tickPerRotation)
{
    pinPWM = _pinPWM;
    pinDirFoward = _pinDirFoward;
    pinDirBackward = _pinDirBackward;
    tickPerRotation = _tickPerRotation;
    pinMode(pinPWM, OUTPUT);
    pinMode(pinDirFoward, OUTPUT);
    pinMode(pinDirBackward, OUTPUT);
}

void Motor::setEncoder(Encoder &_enc)
{
encoder = _enc;
}

void Motor::setPid(Pid &_pid)
{
  pid = _pid;
}

void Motor::setSpeed(uint8_t speed, uint8_t dir, uint32_t delta)
{
  analogWrite(pinPWM, pid.calculate(delta, speed, delta));
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

void Motor::stop()
{
  digitalWrite(pinPWM, 0);
  digitalWrite(pinDirBackward, 0);
  digitalWrite(pinDirFoward, 0);

}