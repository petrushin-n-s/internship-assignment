
// ЛР9. Пример 2. Последовательный интерфейс I2C. Обработка информации от датчиков
// Отправка данных c OrangePi на Ардуино через I2C

#include <Wire.h>
void setup() {
  Wire.begin(0x23);
  Wire.onRequest(reqINT);
}
byte data;
void loop()
{
  data = analogRead(A0) >> 2;
  delay(100);
}
void reqINT()
{
  Wire.write(data);
}
