#include <GyverStepper.h>

int command;
int delta = 1000;
int distanse = delta;
int listanse;
int ristanse;
int kit;

void doing(int comand)
{
  if (comand == 8) {
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

  Serial.println("Полный Вперёд!");
  stepperL.setTarget(listanse, RELATIVE);
  stepperR.setTarget(ristanse, RELATIVE);
}

void stoping() {
  listanse = (delta / 2) * (listanse / distanse);
  ristanse = (delta / 2) * (ristanse / distanse);
  Serial.println("Полный СТОП!!!");
  stepperL.setTarget(listanse, RELATIVE);
  stepperR.setTarget(ristanse, RELATIVE);
}

GStepper< STEPPER2WIRE> stepperL(1, 2, 3, 4);
GStepper< STEPPER2WIRE> stepperR(1, 5, 6, 7);

void setup() {
  Serial.begin(115200);
  stepperL.setRunMode(FOLLOW_POS);
  stepperL.setMaxSpeed(delta);
  stepperL.setAcceleration(delta / 2);

  stepperR.setRunMode(FOLLOW_POS);
  stepperR.setMaxSpeed(delta);
  stepperR.setAcceleration(delta / 2);
}
void loop() {

  if (stepperL.tick() && stepperR.tick()) {
    if (Serial.available())
      stoping();
  }
  else {
    if (Serial.available()) {
      command = Serial.readString().toInt();
      Serial.print("Команда - ");
      Serial.println(command);
      kit = millis();
    }
    if (!stepperL.tick() && !stepperR.tick() && command >= delta) {
      Serial.println("Поправка в конституцию");
      distanse = command;
    }
    else if (millis() - kit > 1000) {
      Serial.println("Стою");
      command = 0;
    }
    else
      doing(command);
  }
}
