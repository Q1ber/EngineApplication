#include <iostream>
#include <locale.h>
#include "MainFunction.h"
#include "ClassEngine.h"

#define SIZE 100;

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");

	Menu();

	return 0;
}