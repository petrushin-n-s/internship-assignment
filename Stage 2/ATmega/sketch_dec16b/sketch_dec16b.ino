// ЛР 5. Задание 2.
void setup() {
  // put your setup code here, to run once:
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);

  pinMode (2, INPUT_PULLUP);
  pinMode (3, INPUT_PULLUP);
  pinMode (5, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == 0)
    digitalWrite(10, HIGH);
  else
    digitalWrite(10, LOW);

  if (digitalRead(3) == 0)
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
  if (digitalRead(5) == 0)
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);
}
