#include <GyverStepper.h>

GStepper< STEPPER2WIRE> stepperL(3328, 2, 4, 7);
GStepper< STEPPER2WIRE> stepperR(3328, 8, 12, 13);

int command;
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

  if (!stepperL.tick()) {
    if (Serial.available()) {
      command = Serial.read() - 48;
      Serial.println(command);

      if (command == 8) {
        
        Serial.println("qq");
        stepperL.setTarget(1000, RELATIVE);
        Serial.println("qq");
      }
      else if (command == 2) {
        movingBack(1000);
      }
      else if (command == 6) {
        rotateRight(1000);
      }
      else if (command == 4) {
        rotateLeft(1000);
      }
    }
  }
}
