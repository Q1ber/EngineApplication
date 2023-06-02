#include <iostream>
#include <locale.h>
#include "MainFunction.h"
#include "ClassEngine.h"

int main()
{
	//Меняем язык
	setlocale(LC_ALL, "rus");
	//Для корректного отображения кириллицы в cmd
	system("chcp 1251");
	//Вызов основной функции
	Menu();

	return 0;
}