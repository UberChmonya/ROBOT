#include "main.h"

void setup() {
  motorL.SetEncoder(encL);
  motorR.SetEncoder(encR);
  robot.setMotor(motorL, motorR);
  Serial.begin(115200);
  robot.setCoef(30, 1, 1);
 //robot.move(100);
  robot.rotate(90);

}

void loop() {



}