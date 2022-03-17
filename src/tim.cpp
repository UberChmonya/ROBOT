#include "tim.h"
Timer::Timer()
{
    newTime, oldTime = micros();
}

void Timer::Time()
{
    oldTime = newTime;
    newTime = micros();

}

int32_t Timer::Delta()
{
    return newTime - oldTime;
}

void Timer::reset()
{
    newTime, oldTime = micros();
}