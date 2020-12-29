// ЛР7. Пример 4.
#define PIN_LED 9
void setup() {
pinMode (PIN_LED, OUTPUT);
}
void loop() {
int ADCValue = analogRead(A0);
ADCValue = ADCValue>>2;
analogWrite(PIN_LED, ADCValue);
delay(10);
}
