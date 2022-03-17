#include "PID.h"
Pid::Pid(float _kP,float _kI,float _kD,int _minOut,int _maxOut)
{
kP = _kP ;
kI = _kI ;
kD = _kD ;
minOut= _minOut;
maxOut= _maxOut;
}

int Pid::calculate(int input,float setpoint,float Dt)
{
    err = setpoint - input;
    int result = integral + (float)err * Dt * kI;

    if (result > maxOut) integral = maxOut;
    else if (result < minOut) integral =  minOut;
    else integral  = result;

    float D = (err - prevErr) / Dt;
    prevErr = err;
    result = err * kP + integral + D * kD, minOut, maxOut;
    
    if (result > maxOut) return maxOut;
    else if (result < minOut) return minOut;
    else return result;
}