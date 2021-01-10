#include <wiringPi.h>
#include <wiringPiI2C.h>
// ЛР9. Пример 2. Последовательный интерфейс I2C. Обработка информации от датчиков
// Отправка данных c OrangePi на Ардуино через I2C


 #include <wiringPi.h>
 #include <wiringSerial.h>
 #include <wiringPiI2C.h>
int main (){
	wiringPiSetup ();
	int fdi2c,fduart;
	int data;
	fdi2c = wiringPiI2CSetup(0x23);
	fduart = serialOpen("/dev/ttyS2",9600);


	while (1) {
		data = wiringPiI2CRead(fdi2c);
		serialPrintf(fduart,"%d", data);
		serialPrintf(fduart, "\n");
		delay(1000);
	}
	return 0;
}
