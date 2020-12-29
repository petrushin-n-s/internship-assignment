#include <wiringPi.h>

//ЛР 7. Задание 1. Сервопривод в 3 состояниях + зажигание светодиодов

#define DELAY 1000

void switchOnLED(int n) {
  if (n == 0)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  if (n == 1)
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
  if (n == 2)
    digitalWrite(14, HIGH);
  else
    digitalWrite(14, LOW);
}

int main(void) {
  wiringPiSetup();
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);

  pinMode(7, OUTPUT);

  int k = 1;
  int n = 0;
  int j = 500;

  while (1) {
    switchOnLED(n);
    for (int i = 0; i < 50; i++) {
      digitalWrite(7, HIGH);
      delayMicroseconds(j);
      digitalWrite(7, LOW);
      delayMicroseconds(20000 - j);
    }

    j += DELAY * k;
    n += k;

    if ((n == 2) || (n == 0)) {
      k = -k;
    }

  }
  return 0;
}