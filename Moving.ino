#include <GyverStepper.h>

GStepper< STEPPER2WIRE> stepperL(1000, 2, 3, 4);
GStepper< STEPPER2WIRE> stepperR(1000, 5, 6, 7);

int command;
int delta = 1000;
int distanse = 1000;
int listanse;
int ristanse;
int regime = 1;
int kit = 0;

void doing(int comand)
{
  if (comand == 5) {
    regime = -regime;
  }

  if (regime == 1) {
    if (comand == -5) {
      distanse = distanse + delta;
      Serial.println("Дистанция увеличена, милорд");
    }
    else if (comand == -3 && distanse > 1000) {
      distanse = distanse - delta;
      Serial.println("Дистанция уменьшена, милорд");
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
  }
  else {
    if (comand == 0)
      regime = -regime;
    else if (Serial.available()) {
      String i = Serial.readString();
      Serial.println(i);
    }
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
    command = Serial.readString().toInt();
    Serial.println(command);
    kit = millis();
  }

  if (command == 0) {
    doing(command);
  }
  else if (!stepperL.tick() || !stepperR.tick()) {
    if (millis() - kit > 1000)
      command = 0;
    else
      doing(command);
  }
}
