#pragma once
#include "Arduino.h"
class Timer
{
    private:
    uint32_t oldTime, newTime;

    public:
    float delta;
    Timer();
    void Time();
    void reset();
};