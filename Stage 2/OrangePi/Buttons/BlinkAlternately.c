 #include <wiringPi.h>

 // �������� �� ������� c ��������� � ���������� 
 // �� 5. ������� 4.
 int main(void) {
   wiringPiSetup();
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(14, OUTPUT);
   while (1) {

     digitalWrite(12, HIGH);
     delay(500);
     digitalWrite(12, LOW);
     delay(500);

     digitalWrite(13, HIGH);
     delay(500);
     digitalWrite(13, LOW);
     delay(500);

     digitalWrite(14, HIGH);
     delay(500);
     digitalWrite(14, LOW);
     delay(500);

   }
   return 0;
 }