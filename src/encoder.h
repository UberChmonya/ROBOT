#pragma once
#include "Arduino.h"
#include "fast.h"
#include "tim.h"
class Encoder{
    private:
    bool trig;
    int8_t pin1, pin2;
    Timer tim;

    public:
    int32_t delta;
    int count;
    Encoder (); // dont use!!!!!
    Encoder (uint8_t _pin1, uint8_t _pin2);
    bool check();
};