#include "MainFunction.h"
#include "ClassEngine.h"
#include "DynamicMassive.h"
#include "Find.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;



void Header(int i, string NameHeader)
{
	system("cls");
	cout << "-----------------------" << NameHeader << "------------------------------" << endl;
	cout << "-----------------------Запись №" << i + 1 << "--------------------------" << endl;
}

void Menu()
{
	int operation = 0;
	int n = 0;
	Engine MassEngine[100];

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
		cout << "~Для выхода из программы нажмите ESC~"             << endl;
		operation = _getch();
		switch (operation)
		{
		case 49:
			system("cls");
			MassEngine[n].Add();
			system("pause");
			n++;
			break;
		case 50:
			for (int i = 0; i < n; ++i)
			{
				Header(i, "Вывод двигателей");
				MassEngine[i].Cout();
				system("pause");
			}
			break;
		case 51:
		{
			int key = 0; int N = 0;

			for (int i = 0; i < n; ++i)
			{
				Header(i, "Редактор");
				MassEngine[i].Cout();
				cout << "Для выбора двигателя нажмите Enter" << endl;
				cout << "Следующая запись Пробел" << endl;
				key = _getch();
				if (key == 13){N = i;break;}
			}
			if (key == 13) MassEngine[N].Edit();

			break;
		}
		case 52:
		{
			int key = 0; int N = 0;

			for (int i = 0; i < n; ++i)
			{
				system("cls");
				Header(i, "Уничтожитель");
				MassEngine[i].Cout();
				cout << "Для выбора двигателя нажмите Enter" << endl;
				cout << "Следующая запись Пробел" << endl;
				key = _getch();
				if (key == 13){N = i;break;}
			}
			if (key == 13)
			{
				for (int i = N + 1; i < n; ++i)
				{
					MassEngine[i - 1] = MassEngine[i];
					MassEngine[i] = {};
				}
				n--;
				system("cls");
				cout << "Запись успешно удалена" << endl;
				system("pause");
			}

			break;
		}
		case 53:
		{
			{
				int key = 0;
				int position = 0;
				string UserSearch = "";
				int UserSearchNum = 0;

				system("cls");
				cout << "---------------------------Найти двигатель-----------------------------" << endl;
				cout << "Выберите параметр для поиска, нажав цифру:" << endl;
				cout << "[1] - Название " << endl;
				cout << "[2] - Род тока " << endl;
				cout << "[3] - Мощность " << endl;
				cout << "[4] - Номинальное напряжение " << endl;
				cout << "[5] - Номинальный ток " << endl;
				cout << "[6] - Номинальная частота вращения " << endl;
				cout << "[7] - КПД " << endl;
				cout << "[8] - Масса " << endl;
				key = _getch();

				if (key == 49) key = 1;
				else if (key == 50) key = 2;
				else if (key == 51) key = 3;
				else if (key == 52) key = 4;
				else if (key == 53) key = 5;
				else if (key == 54) key = 6;
				else if (key == 55) key = 7;
				else if (key == 56) key = 8;

				if (key == 1)
				{
					system("cls");
					cout << "Поиск по имени" << endl;
					cout << "Введите ваш запрос:";
					getline(cin, UserSearch);
					for (int i = 0; i < n; ++i) FindName(MassEngine[i],UserSearch,key,i);
				}
				else if (key == 2) 
				{
					system("cls");
					cout << "Поиск по типу" << endl;
					string UserSearch = SelectFun("Постоянный", "Переменный");
					for (int i = 0; i < n; ++i) FindName(MassEngine[i],UserSearch,key,i);
				}
				else if (key >= 3 and key <= 8)
				{
					system("cls");
					cout << "Числовой поиск" << endl;
					cout << "Введите ваш запрос:";
					cin >> UserSearchNum;
					cout << "Выберите вариант поиска, нажав цифру:" << endl;
					cout << "[1] - Искать значения равные " << UserSearchNum << endl;
					cout << "[2] - Искать значения меньше " << UserSearchNum << endl;
					cout << "[3] - Искать значения больше " << UserSearchNum << endl;
					position = _getch();
					for (int i = 0; i < n; ++i) FindNumber(MassEngine[i],UserSearchNum,key,position,i);
				}
				else cout << "Неверная цифра" << endl;
			}

			break;
		}
		case 54:
		{

			break;
		}
		case 55:

			break;
		}
	}
}

string SelectFun(string var1, string var2)
{
	cout << "Выберите тип двигателя:" << endl
		 << "[1] - " << var1 << endl
		 << "[2] - " << var2 << endl;
	while (true)
	{
		int Key = _getch();
		if (Key == 49) return var1;
		else if (Key == 50) return var2; 
			else cout << "Выбрана неверная клавиша" << endl
					  << "Попробуйте ещё раз: "     << endl;
	}
}

