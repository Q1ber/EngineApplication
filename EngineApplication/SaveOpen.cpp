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
	FileEngine << "[Num]" << "/" << n << "/" << endl;
	for (int i = 0; i<n; ++i)
	{ 
		FileEngine 
		<< "NL"                                      << endl 
		<< "[N]"   << "/" << engine[i].Get(1) << "/" << endl
		<< "[T]"   << "/" << engine[i].Get(2) << "/" << endl
		<< "[P]"   << "/" << engine[i].Get(3) << "/" << endl
		<< "[V]"   << "/" << engine[i].Get(4) << "/" << endl
		<< "[C]"   << "/" << engine[i].Get(5) << "/" << endl
		<< "[R]"   << "/" << engine[i].Get(6) << "/" << endl
		<< "[E]"   << "/" << engine[i].Get(7) << "/" << endl
		<< "[M]"   << "/" << engine[i].Get(8) << "/" << endl;
	}
	FileEngine.close();

	cout << "Файл успешно сохранён!" << endl;
	system("pause");
}

int OpenFile(Engine engine[])
{
	string NameFile;
	string line;
	string copyS;
	int sIn = 0, sOut = 0;
	int n = -1;
	char c = 0;

	cout << "Введите имя файла, который хотите открыть: ";

	getline(cin, NameFile);

	ifstream in(NameFile + ".txt");

	if (in.is_open())
	{
		while (getline(in, line))
		{
			if (line.find("Num"))
			{
				sIn = line.find("/") + 1;
				sOut = line.find("/", sIn);
				copyS = {};
				for (sIn; sIn < sOut; sIn++) copyS += line[sIn];
				cout << "Количество записей в файле: " << copyS;
			}
			if (line.find("NL")) n++;
			if (line.find("N"))
			{
				sIn = line.find("/") + 1;
				sOut = line.find("/", sIn);
				for (sIn; sIn < sOut; sIn++) copyS += line[sIn];


			}

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
