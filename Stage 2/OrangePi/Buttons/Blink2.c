 #include <wiringPi.h>
 #include <stdbool.h>

 //смена порядка мерцания при нажатии на кнопку
 //ЛР 5. Задание 3.

 int main(void) {
   wiringPiSetup();
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(14, OUTPUT);

   pinMode(3, INPUT);
   pullUpDnControl(3, PUD_UP);
   bool b = true;
   while (1) {

     if (digitalRead(3) == 0)
       b = !b;

     if (b)

       for (int i = 0; i <= 7; i++) {
         if (i & 0x01)
           digitalWrite(14, LOW);
         else
           digitalWrite(14, HIGH);
         if (i & 0x02)
           digitalWrite(12, LOW);
         else
           digitalWrite(12, HIGH);
         if (i & 0x04)
           digitalWrite(13, LOW);
         else
           digitalWrite(13, HIGH);
         delay(250);
       }

     else
       for (int i = 0; i <= 7; i++) {
         if (i & 0x01)
           digitalWrite(13, LOW);
         else
           digitalWrite(13, HIGH);
         if (i & 0x02)
           digitalWrite(12, LOW);
         else
           digitalWrite(12, HIGH);
         if (i & 0x04)
           digitalWrite(14, LOW);
         else
           digitalWrite(14, HIGH);
         delay(250);
       }

   }
   return 0;
 }