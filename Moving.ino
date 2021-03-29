#include <GyverStepper.h>

GStepper< STEPPER2WIRE> stepperL(3328, 2, 4, 7);
GStepper< STEPPER2WIRE> stepperR(3328, 8, 12, 13);

String command;
int distanse;

void  movingForward(int distanse) {
  stepperL.setTarget(-distanse, RELATIVE);
  stepperR.setTarget(distanse, RELATIVE);
}
void  movingBack(int distanse) {
  stepperL.setTarget(distanse, RELATIVE);
  stepperR.setTarget(-distanse, RELATIVE);
}
void  rotateRight(int distanse) {
  stepperL.setTarget(-distanse, RELATIVE);
  stepperR.setTarget(-distanse, RELATIVE);
}
void  rotateLeft(int distanse) {
  stepperL.setTarget(distanse, RELATIVE);
  stepperR.setTarget(distanse, RELATIVE);
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
    command = Serial.readString();
    Serial.println(command);

    if (command == "Forward") {
      stepperL.setTarget(1000, RELATIVE);
    }
    else if (command == "Back") {
      movingBack(1000);
    }
    else if (command == "Right") {
      rotateRight(1000);
    }
    else if (command == "Left") {
      rotateLeft(1000);
    }
  }
}
