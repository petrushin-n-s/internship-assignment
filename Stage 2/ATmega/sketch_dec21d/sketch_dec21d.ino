// ЛР8. Задание 1. Вывод показания потенциометра по запросу пользователя

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
}

String s;
unsigned int angle = 0;

void serialEvent() {
  { angle = analogRead(A0);
    Serial.write(angle);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
