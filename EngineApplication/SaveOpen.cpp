#include "SaveOpen.h"
#include "ClassEngine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void CreateFile( Engine engine[], int n)
{
	system("cls");
	string Name = {};
	cout << "~Сохранение данных в файл~" << endl;
	cout << "Как вы хотите назвать файл?" << endl;
	cout << "Ввод: ";
	_getch();
	cin.ignore();
	getline(cin, Name);

	ofstream FileEngine(Name + ".txt");
	for (int i = 0; i<n; ++i)
	{ 
		FileEngine 
		<< "--------------------------------------------------"                            << endl 
		<< "Двигатель №"             << i+1 << "|" <<                     "|"              << endl
		<< "Название двигателя: "           << "|" << engine[i].Get(1) << "|"              << endl
		<< "Род тока: "                     << "|" << engine[i].Get(2) << "|"              << endl
		<< "Мощность: "                     << "|" << engine[i].Get(3) << "|" << " кВт"    << endl
		<< "Номинальное напряжение: "       << "|" << engine[i].Get(4) << "|" << " В"      << endl
		<< "Номинальный ток: "              << "|" << engine[i].Get(5) << "|" << " А"      << endl
		<< "Номинальная частота вращения: " << "|" << engine[i].Get(6) << "|" << " об/мин" << endl
		<< "КПД: "                          << "|" << engine[i].Get(7) << "|" << " %"      << endl
		<< "Масса: "                        << "|" << engine[i].Get(8) << "|" << " кг"     << endl
		<< "--------------------------------------------------"                            << endl;
	}
	FileEngine.close();

	cout << "Файл успешно сохранён!" << endl;
	system("pause");
}

int OpenFile(Engine engine[])
{
	string NameFile;
	string line;
	char c = 0;
	int count = 0;

	cout << "Введите имя файла, который хотите открыть: ";

	getline(cin, NameFile);

	ifstream in(NameFile + ".txt");

	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	in.close();
	system("pause");
	return 0;
}

void DeleteFile(string Name)
{

}
