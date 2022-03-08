#include "main.h"

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

}