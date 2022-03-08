#include "encoder.h"
Encoder::Encoder(){} // dont use!!!!


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