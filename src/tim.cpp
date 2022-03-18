#include "tim.h"
Timer::Timer()
{
    newTime = micros();
    oldTime = micros();
}

void Timer::Time()
{
    oldTime = newTime;
    newTime = micros();
    delta = (float)(newTime - oldTime) / 1000000.0;

}

void Timer::reset()
{
    newTime = micros();
    oldTime = micros();
}