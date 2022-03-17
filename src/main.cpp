#include "main.h"
#include "tim.h"
void setup() {
  motorL.SetEncoder(encL);
  motorR.SetEncoder(encR);
  robot.setMotor(motorL, motorR);
  robot.setPid(pidWheelL, pidWheelR);
  
  Timer tickL = Timer();
  Timer tickR = Timer();
  Serial.begin(115200);

}

static uint8_t state = 1; 
// state 0: stop,
// state 1: move, 
// state 2: rotate 

static uint8_t speed = 20;// mm sec
static int16_t angle = 90;// gradus

void loop() {
  if(distanse >= 1000)
  {
    state = 0;
    robot.pidWheelL.reset();
    robot.pidWheelR.reset();
  }
  else 
  {
    state = 1;

  }

  if(encL.check() || encR.check())
  {
    if (state == 1)//move
    {
      robot.runSpeed(speed, encL.delta, encR.delta);
    }


  }
}