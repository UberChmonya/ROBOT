#pragma once
#include "Arduino.h"
class Timer
{
    private:

    public:
    uint32_t oldTime, newTime;
    Timer();
    int32_t Delta();
    void Time();
}