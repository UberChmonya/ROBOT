#pragma once
#include <arduino.h>
#include "fast.h"
class Encoder{
    private:
    bool trig;
    int8_t pin1, pin2;

    public:
    int count;
    Encoder (); // dont use!!!!!
    Encoder (uint8_t _pin1, uint8_t _pin2);
    void check();
};