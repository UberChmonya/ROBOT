#pragma once
class Pid
{
    private:

        float kP, kI, kD, err, D;
        int minOut, maxOut;
        float integral = 0, prevErr = 0;

    public:

        Pid(float _kP,float _kI,float _kD,int _minOut,int _maxOut);
        int calculate(int input,float setpoint,float Dt);
        void reset();

};