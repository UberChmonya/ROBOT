#include "Arduino.h"
#include "robot.h"

enum state
{
  stop,
  move,
  rotate
};

Encoder encL =  Encoder(15, 14);
Encoder encR =  Encoder(16, 17);

Motor motorL = Motor(9, 5, 6, 240);
Motor motorR = Motor(3, 4, 2, 240);

Pid pidWheelL = Pid(1.0, 1.0, 1.0, 50, 200);
Pid pidWheelR = Pid(1.0, 1.0, 1.0, 50, 200);

Timer timEcnL = Timer();
Timer timEncR = Timer();
Robot robot = Robot(169, 65);