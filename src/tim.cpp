#include "tim.h"
Timer::Timer()
{
    newTime, oldTime = micros();
}
Timer::Time()
{
    oldTime = newTime;
    newTime = micros();

}
int32_t Timer::Delta()
{
    return newTime - oldTime;
}