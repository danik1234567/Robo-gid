#include <GyverStepper.h>

GStepper< STEPPER2WIRE> stepperL(1024, 2, 3, 4);
GStepper< STEPPER2WIRE> stepperR(1024, 5, 6, 7);

int command;
int distanse = 1024;
int listanse;
int ristanse;

void doing(int comand)
{



  if (comand == -5) {
    distanse = distanse + 1024;
    Serial.println("Дистанция увеличена, милорд");
  }
  else if (comand == -3 && distanse > 1024) {
    distanse = distanse - 1024;
    Serial.println("Дистанция уменьшена, милорд");
  }

  else if (comand == 5) {
    if (Serial.available()) {
      distanse = Serial.readString().toInt();
      Serial.println("New distanse!");
    }
    Serial.println("Change distanse!");
  }
  else if (comand == 8) {
    listanse = -distanse;
    ristanse = distanse;
  }
  else if (comand == 2) {
    listanse = distanse;
    ristanse = -distanse;
  }
  else if (comand == 4) {
    listanse = distanse;
    ristanse = distanse;
  }
  else if (comand == 6) {
    listanse = -distanse;
    ristanse = -distanse;
  }
  else if (comand == 0) {
    listanse = 0;//listanse / distanse;
    ristanse = 0;//ristanse / distanse;
  }

  stepperL.setTarget(listanse, RELATIVE);
  stepperR.setTarget(ristanse, RELATIVE);
}

void setup() {
  Serial.begin(115200);
  stepperL.setRunMode(FOLLOW_POS);
  stepperL.setMaxSpeed(1000);
  stepperL.setAcceleration(500);

  stepperR.setRunMode(FOLLOW_POS);
  stepperR.setMaxSpeed(1000);
  stepperR.setAcceleration(500);
}
void loop() {
  if (Serial.available()) {
    command = Serial.read() - 48; //String().toInt();
    Serial.println(command);
  }

  if (command == 0) {
    doing(command);
  }
  else if (!stepperL.tick() || !stepperR.tick()) {
    doing(command);
    command = 0;
  }
}
