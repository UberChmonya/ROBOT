#include "main.h"

void setup() {
  motorL.SetEncoder(encL);
  motorR.SetEncoder(encR);
  Serial.begin(115200);

}

void loop() {
  Serial.print (motorL.encoder.count);
  Serial.print (motorR.encoder.count);
}