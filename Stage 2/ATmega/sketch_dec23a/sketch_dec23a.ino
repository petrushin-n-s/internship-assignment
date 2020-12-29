#include <time.h>
#include <Servo.h>

// ЛР8. Задание 3. Задание повышенной сложности. Настройка и использование UART в OrangePi
// Отправка данных c OrangePi на Ардуино через UART

#define YEARS 946080000; // непонятная разница в 30 лет между Orange Pi и Ардуино
#define HOURS 10800; // Разница в 3 часа с временем по гринвичу (прибавляем эти секунды и получаем московское время)
#define ANGLE 90;
Servo myservo;

void setup() //Процедура инициализации
{
  Serial.begin (9600); //инициализация (открытие)порта
  //со скоростью 9600бит/c
  pinMode(9, OUTPUT); //инициализация светодиода
  // pinMode(8, OUTPUT); //инициализация светодиода

  myservo.attach(10);
}
time_t nowTime;

int angle = 0;
unsigned int n;
//unsigned int j;
int k = 1;
void loop() //основная процедура
{
  if (Serial.available() > 0) { //проверка буфера, получена ли
    //информация
    digitalWrite(9, HIGH); //то зажечь светодиод

    nowTime = Serial.parseInt(); //чтение информации из буфера
    nowTime -= YEARS;
    nowTime += HOURS;

    struct tm * ptm;
    ptm = gmtime ( &nowTime );

    if ((ptm->tm_wday > 0) && (ptm->tm_wday < 6))
      if ((ptm->tm_hour > 9)  && (ptm->tm_hour < 19)) {
        angle += 90 * k;
        n += k;

        if ((n == 2) || (n == 0)) {
          k = -k;
        }

        myservo.write(angle); // поворот привода на заданный градус
      }

    Serial.println(ptm -> tm_hour);
    //if (ptm -> tm_wday == 0)
    //digitalWrite(8, HIGH);
    //else
    //digitalWrite(8, LOW);
  }
  else
    digitalWrite(9, LOW); //то зажечь светодиод

  delay(30000);
}
