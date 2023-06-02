#include "ClassEngine.h"
#include "CinCheck.h"
#include "MainFunction.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void Engine::Header(int i, string NameHeader)
{
	system("cls");
	cout << "--------------------------------------------------------------------" << endl;
	cout << "~" << NameHeader << endl;
	cout << "~Запись №" << i + 1 << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

string Engine::Change(string Name, bool flag)
{
	system("cls");
	cout << "Прежнее значение: " << Name << endl;
	cout << "Новое значение: ";
	if (flag == 1)
	{
		getline(cin, Name);
		return Name;
	}
	else return Type = Select("Постоянный", "Переменный");
}

string Engine::Select(string var1, string var2)
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
			<< "Попробуйте ещё раз: " << endl;
	}
}

string Engine::Get(int n)
{
	if (n == 1)   return Name;
	if (n == 2)   return Type;
	if (n == 3)   return Power;
	if (n == 4)   return Voltage;
	if (n == 5)   return Current;
	if (n == 6)   return RPM;
	if (n == 7)   return EFF;
	if (n == 8)   return Mass;
}


void Engine::Add()
{
	system("cls");
	cout << "------------------------Ввод двигателя------------------------------" << endl;
	cout << "Введите название электрического двигателя: ";
	cin >> Name;
	Type = Select("Постоянный", "Переменный");
	cout << "Введите мощность, кВт: ";
	Power = CinCheck(Power);
	cout << "Введите номинальное напряжение, В : ";
	Voltage = CinCheck(Voltage);
	cout << "Введите номинальный ток, A: ";
	Current = CinCheck(Current);
	cout << "Введите номинальную частоту вращения, об/мин: ";
	RPM = CinCheck(RPM);
	cout << "Введите КПД, %: ";
	EFF = CinCheck(EFF);
	cout << "Введите массу, кг: ";
	Mass = CinCheck(Mass);
	cout << "--------------------------------------------------------------------" << endl;
	system("pause");
}

int Engine::Cout(Engine engine[], int n, string NameHeader, int flag)
{
	int key = 0; int N = 0;
	int i = 0;
	
	if (flag == 3) { i = n; n++; }

	for(i; i < n; ++i)
	{
		Header(i, NameHeader);
		cout << "Название: "                     << engine[i].Name                 << endl;
		cout << "Род тока: "                     << engine[i].Type                 << endl;
		cout << "Мощность: "                     << engine[i].Power   << " кВт"    << endl;
		cout << "Номинальное напряжение: "       << engine[i].Voltage << " В"      << endl;
		cout << "Номинальный ток: "              << engine[i].Current << " А"      << endl;
		cout << "Номинальная частота вращения: " << engine[i].RPM     << " об/мин" << endl;
		cout << "КПД: "                          << engine[i].EFF     << " %"      << endl;
		cout << "Масса: "                        << engine[i].Mass    << " кг"     << endl;
		cout << "--------------------------------------------------------------------" << endl;
		//Редактор
		if (flag == 1)
		{
			cout << "Для выбора двигателя нажмите Enter" << endl;
			cout << "Следующая запись Пробел" << endl;
			key = _getch();
			if (key == 13) { N = i; engine->Edit(engine[N]); break; };
		}
		//Уничтожитель
		if (flag == 2)
		{
			cout << "Для уничтожения нажмите Enter" << endl;
			cout << "Для удаления всех записей нажмите BACKSPACE" << endl;
			cout << "Следующая запись Пробел" << endl;
			key = _getch();
			if (key == 13)
			{
				for (int i = N + 1; i < n; ++i)
				{
					engine[i - 1] = engine[i];
					engine[i] = {};
				}
				system("cls");
				cout << "Запись успешно удалена" << endl;
				system("pause");
				return n-1;
			}
			if (key == 8) return 0;
		}
		system("pause");
	}
}

void Engine::Edit(Engine engine)
{
	int operation = 0;
	system("cls");
	cout << "---------------------------Редактор---------------------------------" << endl;
	cout << "Выберите параметр для редактирования, нажав цифру:"                   << endl;
	cout << "[1] - Название "                        << Name					   << endl;
	cout << "[2] - Род тока "                        << Type                       << endl;
	cout << "[3] - Мощность "                        << Power   << " кВт"          << endl;
	cout << "[4] - Номинальное напряжение "          << Voltage << " В"            << endl;
	cout << "[5] - Номинальный ток "                 << Current << " А"            << endl;
	cout << "[6] - Номинальная частота вращения "    << RPM     << " об/мин"       << endl;
	cout << "[7] - КПД "                             << EFF     << " %"            << endl;
	cout << "[8] - Масса "                           << Mass    << " кг"           << endl;
	operation = _getch();
	switch (operation)
	{
	case 49:
		Name = Change(Name,1);
		break;
	case 50:
		Type = Change(Type, 0);
		break;
	case 51:
		Power = Change(Power, 1);
		break;
	case 52:
		Voltage = Change(Voltage, 1);
		break;
	case 53:
		Current = Change(Current, 1);
		break;
	case 54:
		RPM = Change(RPM, 1);
		break;
	case 55:
		EFF = Change(EFF, 1);
		break;
	case 56:
		Mass = Change(Mass, 1);
		break;
	}
}

void Engine::Find(Engine engine[], int n)
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
	//Преобразование для удобства
	if (key == 49) key = 1;
	else if (key == 50) key = 2;
	else if (key == 51) key = 3;
	else if (key == 52) key = 4;
	else if (key == 53) key = 5;
	else if (key == 54) key = 6;
	else if (key == 55) key = 7;
	else if (key == 56) key = 8;
	//Поиск по имени
	if (key == 1)
	{
		system("cls");
		cout << "Поиск по имени" << endl;
		cout << "Введите ваш запрос:";
		getline(cin, UserSearch);
		for (int i = 0; i < n; ++i) if (engine[i].Get(key) == UserSearch) engine->Cout(engine, i, "Результаты поиска:", 3);
	}
	//Поиск по типу
	else if (key == 2)
	{
		system("cls");
		cout << "Поиск по типу" << endl;
		string UserSearch = Select("Постоянный", "Переменный");
		for (int i = 0; i < n; ++i) if (engine[i].Get(key) == UserSearch) engine->Cout(engine, i, "Результаты поиска:", 3);
	}
	//Числовой поиск
	else if (key >= 3 and key <= 8)
	{
		int ValueEngine = 0;

		system("cls");
		cout << "Числовой поиск" << endl;
		cout << "Введите ваш запрос:";
		cin >> UserSearchNum;
		cout << "Выберите вариант поиска, нажав цифру:" << endl;
		cout << "[1] - Искать значения равные " << UserSearchNum << endl;
		cout << "[2] - Искать значения меньше " << UserSearchNum << endl;
		cout << "[3] - Искать значения больше " << UserSearchNum << endl;
		position = _getch();
		for (int i = 0; i < n; ++i)
		{
			ValueEngine = stoi(engine[i].Get(key));
			if (position == 49) if (ValueEngine == UserSearchNum) engine->Cout(engine, i, "Результаты поиска:", 3);
			if (position == 50) if (ValueEngine > UserSearchNum)  engine->Cout(engine, i, "Результаты поиска:", 3);
			if (position == 51) if (ValueEngine < UserSearchNum)  engine->Cout(engine, i, "Результаты поиска:", 3);
		}
	}
	else cout << "Неверная цифра" << endl;
}
