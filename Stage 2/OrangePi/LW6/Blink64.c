 #include<wiringPi.h>

 // ЛР 6. Задание 1. Взаимодействие микроконтроллера ATmega и компьютера OrangePi с помощью логических сигналов

 int main(void) {
   wiringPiSetup();
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(14, OUTPUT);
   pinMode(0, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);

   while (1) {
     for (int i = 0; i <= 63; i++) {
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

       if (i & 0x08)
         digitalWrite(0, LOW);
       else
         digitalWrite(0, HIGH);
       delay(250);

       if (i & 0x10)
         digitalWrite(2, LOW);
       else
         digitalWrite(2, HIGH);
       delay(250);

       if (i & 0x20)
         digitalWrite(3, LOW);
       else
         digitalWrite(3, HIGH);
       delay(250);

     }

   }
   return 0;
 }