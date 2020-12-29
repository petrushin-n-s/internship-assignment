#include <wiringPi.h> //подключение библиотеки Wiring
#include <wiringSerial.h> //подключение библиотеки wiringSerial
#include <stdio.h> //подключение стандартных библиотек си
#include <time.h>
#include <stdlib.h>

// ЛР8. Задание 3. Задание повышенной сложности. Настройка и использование UART в OrangePi
// Отправка данных c OrangePi на Ардуино через UART

static int fd; //объявление переменной описателя устройства

short int n = 0;
char * str = NULL;


void main (void) //точка входа в программу
{
	wiringPiSetup();//инициализация wiring
	fd = serialOpen("/dev/ttyS2",9600);

	struct tm *tm_prt;
	time_t time_now;
//инициализация UART с частотой 9600бит/c
//и передача описателя устройства в fd
	while(1) //начало бесконечного цикла
	{

		time (&time_now);
		tm_prt = gmtime ( &time_now );
		printf("%d \n", time_now );
		serialPrintf(fd, "%d ",time_now); //вывод переменной через UART


		if (serialDataAvail(fd) > 0) { //проверка буфера

			n = serialDataAvail(fd);
			str = (char * ) calloc((n + 1), sizeof(char));

			if (!str)
				printf("Allocation error.");

			for (int i = 0; i < n; i++) {
				str[i] = serialGetchar(fd);
			}

			printf("Data from ATmega %s \n", str);

			free(str);
		}
		delay(1000);
	}

}
