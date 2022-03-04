#include "robot.h"
#include <Arduino.h>

void setup() {
  
  Serial.begin(115200);
}

Encoder Ex =  Encoder(A1, A0);
Encoder Ey =  Encoder(A2, A3);

Motor Mx = Motor(9, 6, 5, 60, Ex);
Motor My = Motor(3, 2, 4, 60, Ey);


void loop() {
  Ex.check();
  Ey.check();
  if (Ex.count< 500)
  {
    Mx.setSpeed(50,0);
  } 
  else Mx.setSpeed(0,0);
    if (Ey.count< 500)
  {
    My.setSpeed(50,0);
  } 
  else My.setSpeed(0,0);
 // Serial.print("x is ");
  Serial.println(Ex.count);
  //Serial.print("y is ");
  //Serial.println(Ey.count);
}