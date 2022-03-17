#include "main.h"
#include "tim.h"
void setup() {
  motorL.setEncoder(encL);
  motorR.setEncoder(encR);
  robot.setMotor(motorL, motorR);
  motorL.setPid(pidWheelL);
  motorR.setPid(pidWheelR);
  Serial.begin(115200);

}

state robotState = stop;
static uint8_t speed = 20;// mm sec
static int16_t angle = 90;// gradus
static uint16_t distanceTarget = 1000;// gradus
static bool encStateL, encStateR = false;

void loop() {

  encStateL = encL.check();
  encStateR = encR.check();

  if(distanceTarget/robot.wheelDiametr/motorL.tickPerRotation * encL.count >= distanceTarget)
  {
    robotState = stop;
    motorL.pid.reset();
    motorR.pid.reset();
  }
  else 
  {
    robotState = move;
  }

  if(encStateL || encStateR)
  {
    if (robotState == move)
    {
      robot.runSpeed(speed, encL.delta, encR.delta);
    }
  }
}
