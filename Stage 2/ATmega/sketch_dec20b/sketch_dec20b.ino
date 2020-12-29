// ЛР7. Пример 5.

#include <Servo.h> //подключение библиотеки
Servo myservo; //определение переменной типа servo
void setup() {
myservo.attach(10); //инициализация сервопривода на выводе с логическим именем 10
}
void loop() {
unsigned int angle=analogRead(A0); //получение значения от потенциометра
angle = angle*0.175; //нормализация значения 180/1024=0.175
myservo.write(angle); // поворот привода на заданный градус
delay(15); //задержка необходимая приводу для поворота
//на указанный в строке выше угол
}