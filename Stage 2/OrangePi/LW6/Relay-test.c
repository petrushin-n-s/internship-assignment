#include <wiringPi.h>
#include <time.h>

//�� 6. ������� 2. ���������� ������� ���������� � ������� ����
//�������� ������� � ������������� ���� ��� � �������

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