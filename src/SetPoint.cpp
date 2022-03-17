#include "SetPoint.h"
SetPoint::SetPoint(int _distanceAccelerator, int _minOut, int _maxOut)
{
    distanceAccelerator  = _distanceAccelerator;
    minOut = _minOut;
    maxOut = _maxOut;
    acceleration = ((maxOut - _minOut) / distanceAccelerator);
}

/* _____
  /     \
 /       \
|         |
*/       
int SetPoint::GetSpeed(int distance,int distanceCurr)
{

    if (distanceCurr <= distanceAccelerator)return minOut + (acceleration * distanceCurr);

    else if(distanceCurr > distanceAccelerator && distanceCurr < distance - distanceAccelerator)return maxOut;

    else return minOut + (acceleration * (distance - distanceCurr));
}
