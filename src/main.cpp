#include "main.h"
#include "tim.h"
void setup() {

  encL.setTimer(timEcnL);
  motorL.setEncoder(encL);
  motorL.setPid(pidWheelL);

  encR.setTimer(timEncR);
  motorR.setEncoder(encR);
  motorR.setPid(pidWheelR);

  robot.setMotor(motorL, motorR);

  Serial.begin(115200);
  Serial.println("L, R");

}

state robotState = stop;
static uint8_t speed = 100;// mm sec
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
    robot.stopMotors();
  }
  else 
  {
    robotState = move;
  }

  if(encStateL || encStateR)
  {

    if (robotState == move)
    {

      robot.runSpeed(speed, encL.timer.delta, encR.timer.delta);
    }
  }
}
