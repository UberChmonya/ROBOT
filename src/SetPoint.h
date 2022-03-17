#pragma once
class SetPoint
{
    private:
    int distanceAccelerator, minOut, maxOut, acceleration;

    public:
    SetPoint(int distanceAccelerator, int minOut, int MaxOut);
    int GetSpeed(int distance,int distanceCurr);
};