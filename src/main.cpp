#include "robot.h"
#include <Arduino.h>

void setup() {
  
  Serial.begin(115200);
}

Encoder Ex =  Encoder(A1, A0);
Encoder Ey =  Encoder(A2, A3);

Motor Mx = Motor(8, 7, 6, 60, Ex);
Motor My = Motor(11, 10, 9, 60, Ey);


void loop() {
  Ex.check();
  Ey.check();
  Serial.println(Ex.count);
  Serial.println(Ey.count);
}