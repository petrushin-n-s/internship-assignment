#include <DHT.h>
#include <Wire.h>

#define CODE 5

DHT dht(2, DHT11);

int h = 0;
int t = 0;

int j = 1;

void setup()
{
  Wire.begin(0x23);
  Wire.onReceive(onRcv);
  Wire.onRequest(onReq);
  //pinMode(8, OUTPUT);
  dht.begin();
}


void loop() {
  digitalWrite(8, LOW);
}

void onReq() {
  // Какой-то ужасный костыль. Но работает
  if (j == 1)
    Wire.write(t);
  else
    Wire.write(h);

  j = -j;
}

void onRcv(int bytescount)
{

  while (0 < Wire.available())
  {
    int c = Wire.read();
    if (c == CODE)   {

      //Почему-то работает только с такой последовательностью задержек и вызовов функций?!? Видимо какие-то проблемы с опросом DHT11.
      delay(2000);
      t = dht.readTemperature();

      delay(2000);
      t = dht.readTemperature();
      delay(2000);
      h = dht.readHumidity();

      //digitalWrite(8, HIGH);
      //delay(1000);
    }
  }
}
