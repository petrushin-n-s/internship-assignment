// ЛР7. Пример 3
#define LED_1 9
#define LED_2 10
void setup() {
pinMode (LED_1, OUTPUT);
pinMode (LED_2, OUTPUT);
}
int gc=255;
int yc=0;
int state = 0;
void loop() {
switch (state){
case 0:
gc-=15;
yc+=15;
if (yc==255)
state=1;
break;
case 1:
yc-=15;
gc+=15;
if (gc==255)
state=0;
break;
}
analogWrite(LED_1, gc);
analogWrite(LED_2, yc);
delay(25);
}
