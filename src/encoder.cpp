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

void Encoder::check()
{
  if ((isHigh(pin1)) & (trig == 0))
  {
    trig = 1;
    if (isHigh(pin2)) count++;
    else count--;
  }
  if ((isLow(pin1)) & (trig == 1)) trig = 0;
}