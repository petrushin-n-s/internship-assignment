#include <wiringPi.h> //подключение библиотеки Wiring
#include <wiringSerial.h> //подключение библиотеки wiringSerial
#include <stdio.h> //подключение стандартных библиотек Си
#include <stdlib.h>
#include <string.h>

// ЛР8. Задание 2. Настройка и использование UART в OrangePi
// Отправка данных на OrangePi через UART
// Зажигание светодиода в зависимости от полученного значения


static int fd; //объявление переменной указателя на устройство

void main (void) //точка входа в программу
{
	wiringPiSetup();//инициализация wiring
	fd = serialOpen("/dev/ttyS2",9600); //инициализация UART с частотой 9600бит/c и передача указателя устройства в fd
	short int n = 0;
	char * str = NULL;
	pinMode(12,OUTPUT);
	pinMode(13,OUTPUT);
		pinMode(14,OUTPUT);


	while (1) //начало бесконечного цикла
	{
		if (serialDataAvail(fd) > 0) { //проверка буфера

			n = serialDataAvail(fd);
			str = (char * ) calloc((n + 1), sizeof(char));

			if (!str)
				printf("Allocation error.");

			for (int i = 0; i < n; i++) {
				str[i] = serialGetchar(fd);
			}

			printf("strlen - %d \n", strlen(str));
			printf("Data from ATmega %s \n", str);

			int i = atoi(str);

			printf("%d \n", i);
			free(str);

			if ((i >= 0) && (i < 85) )
				digitalWrite(13,HIGH); //зажечь светодиод
			else digitalWrite(13,LOW); //потушить светодиод
			if ((i >= 85) && (i < 170) )
				digitalWrite(12,HIGH); //зажечь светодиод
			else digitalWrite(12,LOW); //потушить светодиод
			if ((i >= 170) && (i <= 255) )
				digitalWrite(14,HIGH); //зажечь светодиод
			else digitalWrite(14,LOW); //потушить светодиод

		}
	}
}
