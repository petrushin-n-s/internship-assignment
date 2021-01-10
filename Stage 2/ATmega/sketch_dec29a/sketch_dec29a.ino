// ЛР9. Пример 1. Последовательный интерфейс I2C. Обработка информации от датчиков
// Отправка данных c OrangePi на Ардуино через I2C

#include <Wire.h>
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Wire.begin(0x23);
  Wire.onReceive(recInt);
  Serial.begin(9600);
}
bool k = false;

void loop()
{
  int pin = 9;
  int d;
  if (k) d = 1;
  else d = 0;
  digitalWrite(pin + d, HIGH);
  delay(100);
  digitalWrite(pin + d, LOW);
  delay(100);
}
void recInt(int bytescount)
{
  while (0 < Wire.available())
  {
    int c = Wire.read();
    if (c == 5) k = !k;
    Serial.println(c);
  }
}
