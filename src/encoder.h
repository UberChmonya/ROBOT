#pragma once
#include "Arduino.h"
#include "fast.h"
#include "tim.h"
class Encoder{
    private:
    bool trig;
    int8_t pin1, pin2;
    
    public:
    Timer timer;
    int count;
    Encoder (); // dont use!!!!!
    Encoder (uint8_t _pin1, uint8_t _pin2);

    void setTimer(Timer &tim);
    bool check();
};