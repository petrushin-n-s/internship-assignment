#include <wiringPi.h>
#include <time.h>

//ЛР 6. Задание 2. Управление уличным освещением с помощью реле

int main(void) {
  wiringPiSetup();
  struct tm * tm_prt;
  time_t time_now;
  pinMode(14, OUTPUT);
  while (1) {
    time( & time_now);
    tm_prt = gmtime( & time_now);
    if ((tm_prt -> tm_hour > 19) && (tm_prt -> tm_hour < 23))
      digitalWrite(14, HIGH);
    else digitalWrite(14, LOW);
  }
}