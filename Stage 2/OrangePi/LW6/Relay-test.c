#include <wiringPi.h>
#include <time.h>

//ЛР 6. Задание 2. Управление уличным освещением с помощью реле
//Тестовый вариант с переключением реле раз в секунду

int main(void) {
  wiringPiSetup();
  struct tm * tm_prt;
  time_t time_now;
  pinMode(14, OUTPUT);
  while (1) {
    digitalWrite(14, LOW);
    delay(1000);
    digitalWrite(14, HIGH);
    delay(1000);
  }
}