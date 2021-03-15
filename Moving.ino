#define LS 9 // Вывод управления скоростью вращения левого мотора
#define RS 3 // Вывод управления скоростью вращения правого мотора
#define LDR 7 // Вывод управления направлением вращения левого мотора
#define LDL 6 // Вывод управления направлением вращения левого мотора
#define RDR 4 // Вывод управления направлением вращения правого мотора
#define RDL 5 // Вывод управления направлением вращения правого мотора
#define PIN_TRIG 12 // 
#define PIN_ECHO 11

void movingForward(uint8_t power) {
  analogWrite(LS, power); // Устанавливаем скорость левого мотора
  analogWrite(RS, power); // Устанавливаем скорость правого мотора

  digitalWrite(LDR, LOW);
  digitalWrite(LDL, HIGH);
  digitalWrite(RDR, HIGH);
  digitalWrite(RDL, LOW);
  delay(10);
}

void movingBack(uint8_t power) {
  analogWrite(LS, power);
  analogWrite(RS, power);

  digitalWrite(LDR, HIGH);
  digitalWrite(LDL, LOW);
  digitalWrite(RDR, LOW);
  digitalWrite(RDL, HIGH);
}

void rotateLeft(uint8_t power) {
  analogWrite(LS, power);
  analogWrite(RS, power);

  digitalWrite(LDR, HIGH);
  digitalWrite(LDL, LOW);
  digitalWrite(RDR, HIGH);
  digitalWrite(RDL, LOW);
}

void rotateRight(uint8_t power) {
  analogWrite(LS, power);
  analogWrite(RS, power);

  digitalWrite(LDR, LOW);
  digitalWrite(LDL, HIGH);
  digitalWrite(RDR, LOW);
  digitalWrite(RDL, HIGH);
}

//void turnRight(uint8_t power) {
//  analogWrite(LS, power*2);
//  analogWrite(RS, power/2);
//
//  digitalWrite(LDR, LOW);
//  digitalWrite(LDL, HIGH);
//  digitalWrite(RDR, LOW);
//  digitalWrite(RDL, HIGH);
//}
//
//void turnLeft(uint8_t power) {
//  analogWrite(LS, power/2);
//  analogWrite(RS, power*2);
//
//  digitalWrite(LDR, HIGH);
//  digitalWrite(LDL, LOW);
//  digitalWrite(RDR, HIGH);
//  digitalWrite(RDL, LOW);
//}

void stop_() {
  digitalWrite(LDR, LOW);
  digitalWrite(LDL, LOW);
  digitalWrite(RDR, LOW);
  digitalWrite(RDL, LOW);
}


int command = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  // Установка всех управляющих пинов в режим выхода движок
  pinMode(LS, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(LDR, OUTPUT);
  pinMode(LDL, OUTPUT);
  pinMode(RDR, OUTPUT);
  pinMode(RDL, OUTPUT);

  // Команда остановки двум моторам
  digitalWrite(LDR, LOW);
  digitalWrite(LDL, LOW);
  digitalWrite(RDR, LOW);
  digitalWrite(RDL, LOW);
}

void loop() {
  char read_1 = Serial.read();
  if (read_1 != -1) {
    command = read_1;
    Serial.println(command);
  }

  if (command == 56) {
    movingForward(220);
  }
  else if (command == 50) {
    movingBack(220);
  }

  else if (command == 52) {
    rotateLeft(220);
  }
  else if (command == 54) {
    rotateRight(220);
  }
  else if (command == "Turn right") {
    turnRight(220);
  }
  else if (command == "Turn left") {
    turnLeft(220);
  }
  else if (command == 48) {
    stop_();
  }
}
