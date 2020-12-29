 #include <wiringPi.h>
 //Моргание светодиодом

 int main(void) {
   wiringPiSetup();
   pinMode(14, OUTPUT);
   while (1) {
     digitalWrite(14, HIGH);
     delay(500);
     digitalWrite(14, LOW);
     delay(500);
   }
   return 0;
 }