#include "SetPoint.h"
SetPoint::SetPoint(int _distanceAccelerator, int _minOut, int _maxOut)
{
    distanceAccelerator  = _distanceAccelerator;
    maxOut = _maxOut;
    acceleration = ((maxOut - _minOut) / distanceAccelerator);
}
int SetPoint::GetSpeed(int distance,int distanceCurr)
{

    if (distanceCurr < distance-distanceAccelerator)return acceleration * distanceCurr;

    else if(distanceCurr > distanceAccelerator && distanceCurr < distance - distanceAccelerator)return maxOut;

    else return acceleration * (distance - distanceCurr);
}
