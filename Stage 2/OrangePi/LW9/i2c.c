#include <wiringPi.h>
#include <wiringSerial.h>
#include <wiringPiI2C.h>

#include <stdio.h>
#define CODE 5

// ЛР9. Задание. Последовательный интерфейс I2C. Обработка информации от датчиков
// Обмен данными между Ардуино и OrangePi через I2C

int main (){
	wiringPiSetup ();
	int fdi2c,fduart;
	int data[2];
	fdi2c = wiringPiI2CSetup(0x23);
	fduart = serialOpen("/dev/ttyS2",9600);

	while (1) {
		wiringPiI2CWrite(fdi2c, CODE);
		delay(1000);

		data[0] = wiringPiI2CRead(fdi2c);
		data[1] = wiringPiI2CRead(fdi2c);
		printf("T: %d  H: %d\n", data[0], data[1]);

		serialPrintf(fduart, "T: %d  H: %d\n", data[0], data[1]);
		serialPrintf(fduart, "\n");
		delay(2000);
	}

	return 0;
}
