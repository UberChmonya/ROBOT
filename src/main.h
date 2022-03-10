#include <Arduino.h>
#include "Robot.h"
#include "encoder.h"

Encoder encL =  Encoder(A1, A0);
Encoder encR =  Encoder(A2, A3);

Motor motorL = Motor(9, 6, 5, 60);
Motor motorR = Motor(3, 2, 4, 60);

Robot robot = Robot(300, 50);