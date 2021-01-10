#include <wiringPi.h>
#include <wiringPiI2C.h>
// ЛР9. Пример 1. Последовательный интерфейс I2C. Обработка информации от датчиков
// Отправка данных c OrangePi на Ардуино через I2C

int main ()
{
	wiringPiSetup();
	int fd;
	fd = wiringPiI2CSetup(0x23);
	while (1)
	{ for (int i=0; i<10; i++) {
		  wiringPiI2CWrite(fd,i);
		  delay(1000);
	  }}
}
