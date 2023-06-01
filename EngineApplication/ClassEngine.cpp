#include "ClassEngine.h"
#include "CinCheck.h"
#include "MainFunction.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void Engine::Add()
{
	cout << "------------------------Ввод двигателя------------------------------" << endl;
	cout << "Введите название электрического двигателя: ";
	cin >> Name;
	Type = SelectFun("Постоянный", "Переменный");
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
}

void Engine::Cout()
{
	cout << "Название: "                     << Name                 << endl;
	cout << "Род тока: "                     << Type                 << endl;
	cout << "Мощность: "                     << Power   << " кВт"    << endl;
	cout << "Номинальное напряжение: "       << Voltage << " В"      << endl;
	cout << "Номинальный ток: "              << Current << " А"      << endl;
	cout << "Номинальная частота вращения: " << RPM     << " об/мин" << endl;
	cout << "КПД: " << EFF << " %" << endl;
	cout << "Масса: " << Mass << " кг" << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

void Engine::Edit()
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
		system("cls");
		cout << "Преженее значение: " << Name << endl;
		cout << "Новое значение: ";
		cin >> Name;
		break;
	case 50:
		system("cls");
		cout << "Преженее значение: " << Type << endl;
		cout << "Новое значение: ";
		Type = SelectFun("Постоянный", "Переменный");
		break;
	case 51:
		system("cls");
		cout << "Преженее значение: " << Power << endl;
		cout << "Новое значение: ";
		cin >> Power;
		break;
	case 52:
		system("cls");
		cout << "Преженее значение: " << Voltage << endl;
		cout << "Новое значение: ";
		cin >> Voltage;
		break;
	case 53:
		system("cls");
		cout << "Преженее значение: " << Current << endl;
		cout << "Новое значение: ";
		cin >> Current;
		break;
	case 54:
		system("cls");
		cout << "Преженее значение: " << RPM << endl;
		cout << "Новое значение: ";
		cin >> RPM;
		break;
	case 55:
		system("cls");
		cout << "Преженее значение: " << EFF << endl;
		cout << "Новое значение: ";
		cin >> EFF;
		break;
	case 56:
		system("cls");
		cout << "Преженее значение: " << Mass << endl;
		cout << "Новое значение: ";
		cin >> Mass;
		break;
	}
}

void Engine::Save()
{
	
}

void Engine::Open()
{

}

string Engine::GetVar(int n)
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
