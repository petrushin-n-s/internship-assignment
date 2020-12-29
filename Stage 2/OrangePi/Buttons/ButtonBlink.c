 #include <wiringPi.h>

 // Зажигание светодиодов при нажатии на кнопки
 // ЛР 5. Задание 4.
 int main(void) {
   wiringPiSetup();
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(14, OUTPUT);

   pinMode(3, INPUT);
   pullUpDnControl(3, PUD_UP);

   pinMode(2, INPUT);
   pullUpDnControl(2, PUD_UP);

   pinMode(0, INPUT);
   pullUpDnControl(0, PUD_UP);

   while (1) {
     if (digitalRead(3) == 0)
       digitalWrite(13, HIGH);
     else digitalWrite(13, LOW);

     if (digitalRead(2) == 0)
       digitalWrite(12, HIGH);
     else digitalWrite(12, LOW);

     if (digitalRead(0) == 0)
       digitalWrite(14, HIGH);
     else digitalWrite(14, LOW);

   }
   return 0;
 }