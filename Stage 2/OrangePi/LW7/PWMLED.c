#include <wiringPi.h>

//ЛР 7. Задание 2. Программный ШИМ светодиодов

int main(void) {
  wiringPiSetup();
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  unsigned int tm = 1;
  short int k = 1;
  unsigned short int led = 12;

  while (1) {

    digitalWrite(led, HIGH);
    delayMicroseconds(tm);;
    digitalWrite(led, LOW);
    delayMicroseconds(999 - tm);
    tm = tm + k * 1;
    if ((tm == 999) || (tm == 1)) {
      k = k * (-1);
      if (tm == 1)
        led++;
    }
    if (led == 14)
      led = 12;

  }
}
