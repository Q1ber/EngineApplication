#include "SaveOpen.h"
#include "ClassEngine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdio>

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
	FileEngine << "[]" << "/" << n << "/" << endl;
	for (int i = 0; i<n; ++i)
	{ 
		FileEngine 
		<< "NL"                                      << endl 
		<< "[A]"   << "/" << engine[i].Get(1) << "/" << endl
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

void WriteFile(Engine *engine,string Name,string line,int n)
{
	int sIn = 0, sOut = 0;
	string copyS = {};

	if (line.find(Name) != -1)
	{
		copyS = {};
		sIn = line.find("/") + 1;
		sOut = line.find("/", sIn);
		for (sIn; sIn < sOut; sIn++) copyS += line[sIn];
		if (Name == "Num") cout << "Количество записей в файле: " << copyS << endl;
		else engine->WriteReturn(engine, n, copyS, Name);
	}

}

int OpenFile(Engine *engine)
{
	string NameFile;
	string line;
	int sIn = 0, sOut = 0;
	int n = -1;
	string copyS = {};

	system("cls");
	cout << "Введите имя файла, который хотите открыть: ";
	getline(cin, NameFile);

	ifstream in(NameFile + ".txt");

	if (in.is_open())
	{
		while (getline(in, line))
		{
			if (line == "NL") n++;
			WriteFile(engine, "Num", line, n);
			WriteFile(engine, "A", line, n);
			WriteFile(engine, "T", line, n);
			WriteFile(engine, "P", line, n);
			WriteFile(engine, "V", line, n);
			WriteFile(engine, "C", line, n);
			WriteFile(engine, "R", line, n);
			WriteFile(engine, "E", line, n);
			WriteFile(engine, "M", line, n);
		}
	}
	in.close();

	cout << "Вывод из файла успешно завершён" << endl;
	system("pause");
	return n+1;
}

void DeleteFile()
{
	string FileName;

	system("cls");
	cout << "~Удаление файла~" << endl;
	cout << "Введите название файла: ";

	getline(cin, FileName);
	FileName = FileName + ".txt";

	if (remove(FileName.c_str()) == -1) cout << "Такого файла нет, либо он находится в другой директории" << endl;
	else cout << "Файл успешно удалён" << endl;
	system("pause");
}
