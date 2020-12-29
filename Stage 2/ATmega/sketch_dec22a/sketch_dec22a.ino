// ЛР8. Задание 2. Настройка и использование UART в OrangePi
// Отправка данных на OrangePi через UART

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
}

String s;
unsigned int angle = 0;

void loop() {
  angle = analogRead(A0);
  angle = angle >> 2; 
  Serial.println(angle);
  delay(500);
}
