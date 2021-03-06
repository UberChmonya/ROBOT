#include "encoder.h"
Encoder::Encoder(){} // dont use!!!!

Encoder::Encoder(uint8_t _pin1, uint8_t _pin2)
{
  pin1 = _pin1;
  pin2 = _pin2;
  trig = 0;
  count = 0;
  pinAsInput(pin1);
  pinAsInput(pin2);
  
}

void Encoder::setTimer(Timer &_tim)
{
  timer = _tim;
}

bool Encoder::check()
{
  if ((isHigh(pin1)) & (trig == 0))
  {
    trig = 1;
    timer.Time();

    if (isHigh(pin2))
    {
      count++;
      return true; 
    }
    else
    {
      count--;
      return true;
    }
  }
  if ((isLow(pin1)) & (trig == 1)) trig = 0;
  return false;
}