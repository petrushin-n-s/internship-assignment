# Руководство программисту
####  Третий этап стажировки
##### Выполнил: Петрушин Никита Сергеевич

------------

##### Техническое задание на разработку
«Модуль для работы с системой сборки Buildroot»

1. Наименование разрабатываемой программы

«Модуль для работы с системой сборки Buildroot».

2. Назначение и область применения программы:

Разрабатываемая программа предназначена для выполнения конфигурации ряда
программных компонентов с открытым исходным кодом для встроенного ПО
телекоммуникационных устройств.

------------

В ходе выполнения работ будет использоваться операционная система на основе Debian (Lubuntu 20.04).

Для выполнения заданий необходимо скачать исходный код системы сборки [Buildroot](https://buildroot.org/download.html "Buildroot"). 

Для успешной компиляции Buildroot необходимо установить дополнительные пакеты:
~~which~~, sed, make (версия 3.81 или выше), binutils, build-essential (для дистрибутивов на основе Debian), gcc (версия 2.95 или выше), g++ (версия 2.95 или выше), bash, patch, gzip, bzip2, perl (версия 5.8.7 или выше), tar, cpio, python (версия 2.6 или выше), unzip, rsync, wget, libncurses5-dev, git.

Это можно сделать, выполнив в терминале команду:

`sudo apt install sed make binutils build-essential gcc g++ bash patch gzip bzip2 perl tar cpio python3 unzip rsync wget libncurses5-dev git`

Для выполнения следующей работы (с использованием систем сборки GNU Autotools), необходимы уже установленные на предыдущем этапе пакеты: gcc, make, а также необходимо установить следующий пакет: autotools.

`sudo apt install autotools`

Также для успешной компиляции GNU Nano необходимы следующие пакеты: 
autoconf, automake, autopoint, gcc, gettext, git, groff, make, pkg-config, texinfo

`sudo apt install autoconf automake autopoint gcc gettext git groff make pkg-config texinfo`

Исходный код GNU Nano можно скачать [здесь](https://git.savannah.gnu.org/cgit/nano.git/log/ "здесь") или выполнить команду `git clone git://git.savannah.gnu.org/nano.git nano`. 

Кроме того, необходима библиотека ncurses. Самый простой вариант - это [скачать](https://archlinuxarm.org/packages/arm/ncurses "скачать") уже скомпилированную под ARM версию библиотеки и добавить ее в тулчейн.

Для выполнения следующей работы ("Изучение загрузчика U-Boot") необходимо установить следующие пакеты:
u-boot-tools device-tree-compiler swig ~~libpython-dev~~ 

`sudo apt install u-boot-tools device-tree-compiler swig python3-dev`

Кроме того, мне потребовалось дополнительно установить эти утилиты:

`sudo apt install bison flex`

Исходный код U-Boot можно скачать с данного [сайта](ftp://ftp.denx.de/pub/u-boot/  "сайта").

Файл сжатого образа ядра zImage и файл дерева устройств можно получить при помощи Buildroot. Достаточно выполнить следующие команды: 

````bash
make orangepi_zero_defconfig 
make
````
Скачать исходный код ядра Linux для выполнения ЛР "Компиляция ядра Linux" можно [здесь](https://www.kernel.org/ "здесь").


Для выполнения ЛР №6 "Компиляция программы BusyBox" необходимо скачать программу [BusyBox](https://www.busybox.net/ "BusyBox")

Исходный код калькулятор GNU bc можно скачать [тут](https://www.gnu.org/software/bc/ "тут").