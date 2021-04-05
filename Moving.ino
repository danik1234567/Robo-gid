#include <GyverStepper.h>

GStepper< STEPPER2WIRE> stepperL(1024, 2, 3, 4);
GStepper< STEPPER2WIRE> stepperR(1024, 5, 6, 7);

int command;
int distanse = 1024;

void doing(int comand)
{

  if (comand == -5) {
    distanse = distanse + 1024;
  }
  else if (comand == -3) {
    distanse = distanse - 1024;
    if (distanse < 0)
      distanse = -distanse;
  }

  else if (comand == 8) {
    stepperL.setTarget(distanse, RELATIVE);
    stepperR.setTarget(-distanse, RELATIVE);
  }
  else if (comand == 2) {
    stepperL.setTarget(-distanse, RELATIVE);
    stepperR.setTarget(distanse, RELATIVE);
  }
  else if (comand == 6) {
    stepperL.setTarget(-distanse, RELATIVE);
    stepperR.setTarget(-distanse, RELATIVE);
  }
  else if (comand == 4) {
    stepperL.setTarget(distanse, RELATIVE);
    stepperR.setTarget(distanse, RELATIVE);
  }
}

void setup() {
  Serial.begin(115200);
  stepperL.setRunMode(FOLLOW_POS);
  stepperL.setMaxSpeed(400);
  stepperL.setAcceleration(500);

  stepperR.setRunMode(FOLLOW_POS);
  stepperR.setMaxSpeed(1000);
  stepperR.setAcceleration(500);
}
void loop() {
  if (Serial.available()) {
    command = Serial.read() - 48;
    Serial.println(command);
  }

  if (command == 0)
    doing(command);
  else if (!stepperL.tick() or !stepperR.tick()) {
    doing(command);
  }
}
