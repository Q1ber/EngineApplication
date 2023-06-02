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
	cout << "~���������� ������ � ����~" << endl;
	cout << "��� �� ������ ������� ����?" << endl;
	cout << "����: ";
	_getch();
	cin.ignore();
	getline(cin, Name);

	ofstream FileEngine(Name + ".txt");
	for (int i = 0; i<n; ++i)
	{ 
		FileEngine 
		<< "--------------------------------------------------"                            << endl 
		<< "��������� �"             << i+1 << "|" <<                     "|"              << endl
		<< "�������� ���������: "           << "|" << engine[i].Get(1) << "|"              << endl
		<< "��� ����: "                     << "|" << engine[i].Get(2) << "|"              << endl
		<< "��������: "                     << "|" << engine[i].Get(3) << "|" << " ���"    << endl
		<< "����������� ����������: "       << "|" << engine[i].Get(4) << "|" << " �"      << endl
		<< "����������� ���: "              << "|" << engine[i].Get(5) << "|" << " �"      << endl
		<< "����������� ������� ��������: " << "|" << engine[i].Get(6) << "|" << " ��/���" << endl
		<< "���: "                          << "|" << engine[i].Get(7) << "|" << " %"      << endl
		<< "�����: "                        << "|" << engine[i].Get(8) << "|" << " ��"     << endl
		<< "--------------------------------------------------"                            << endl;
	}
	FileEngine.close();

	cout << "���� ������� �������!" << endl;
	system("pause");
}

int OpenFile(Engine engine[])
{
	string NameFile;
	string line;
	char c = 0;
	int count = 0;

	cout << "������� ��� �����, ������� ������ �������: ";

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
