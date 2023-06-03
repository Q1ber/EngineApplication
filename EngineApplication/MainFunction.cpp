#include "MainFunction.h"
#include "ClassEngine.h"
#include "SaveOpen.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//Основная функция(интерфейс) для взаимодействия с пользователем
void Menu()
{
	//Выбор операции
	int operation = 0;
	//Число элементов массива
	int n = 0;
	//Флаг удаления 
	int flag = 0;
	//Инициализация массива
	Engine MassEngine[100];
	//Вывод главного меняю, пока не нажали ESC
	while (operation != 27)
	{
		system("cls");
		cout << "Выберите дальнейшее действие, нажав цифру:"        << endl;
		cout << "[1] - Добавить электрический двигатель"            << endl;
		cout << "[2] - Просмотреть список электрических двигателей" << endl;
		cout << "[3] - Редактировать электрический двигатель"       << endl;
		cout << "[4] - Удалить электрический двигатель"             << endl;
		cout << "[5] - Найти электрический двигатель"               << endl;
		cout << "[6] - Сохранить данные в базу"                     << endl;
		cout << "[7] - Выгрузить базу данных"                       << endl;
		cout << "[8] - Удалить базу данных"                         << endl;
		cout << "~Для выхода из программы нажмите ESC~"             << endl;
		operation = _getch();
		//Свитч для выбора дальнейшего действия
		switch (operation)
		{
		//Добавления двигателей
		case 49:
			MassEngine[n].Add();
			n++;
			break;
		//Вывод двигателей
		case 50:
			MassEngine->Cout(MassEngine, n,"Вывод двигателей",0);
			break;
		//Редактор двигателей
		case 51:
		{
			MassEngine->Cout(MassEngine, n, "Редактор",1);
			break;
		}
		//Удаление двигателей
		case 52:
		{
			flag = MassEngine->Cout(MassEngine, n, "Уничтожитель", 2);
			if (flag == 1) n--;
			if (flag == 2) n = 0;
			break;
		}
		//Поиск двигателей
		case 53:
		{
			MassEngine->Find(MassEngine, n);
			break;
		}
		//Сохранение файла
		case 54:
		{
			CreateFile(MassEngine, n);
			break;
		}
		//Открытие файла
		case 55:
			n = OpenFile(MassEngine);
			break;
		case 56:
			DeleteFile();
			break;
		}
	}
}



