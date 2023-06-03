#include "MainFunction.h"
#include "ClassEngine.h"
#include "SaveOpen.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//�������� �������(���������) ��� �������������� � �������������
void Menu()
{
	//����� ��������
	int operation = 0;
	//����� ��������� �������
	int n = 0;
	//���� �������� 
	int flag = 0;
	//������������� �������
	Engine MassEngine[100];
	//����� �������� �����, ���� �� ������ ESC
	while (operation != 27)
	{
		system("cls");
		cout << "�������� ���������� ��������, ����� �����:"        << endl;
		cout << "[1] - �������� ������������� ���������"            << endl;
		cout << "[2] - ����������� ������ ������������� ����������" << endl;
		cout << "[3] - ������������� ������������� ���������"       << endl;
		cout << "[4] - ������� ������������� ���������"             << endl;
		cout << "[5] - ����� ������������� ���������"               << endl;
		cout << "[6] - ��������� ������ � ����"                     << endl;
		cout << "[7] - ��������� ���� ������"                       << endl;
		cout << "[8] - ������� ���� ������"                         << endl;
		cout << "~��� ������ �� ��������� ������� ESC~"             << endl;
		operation = _getch();
		//����� ��� ������ ����������� ��������
		switch (operation)
		{
		//���������� ����������
		case 49:
			MassEngine[n].Add();
			n++;
			break;
		//����� ����������
		case 50:
			MassEngine->Cout(MassEngine, n,"����� ����������",0);
			break;
		//�������� ����������
		case 51:
		{
			MassEngine->Cout(MassEngine, n, "��������",1);
			break;
		}
		//�������� ����������
		case 52:
		{
			flag = MassEngine->Cout(MassEngine, n, "������������", 2);
			if (flag == 1) n--;
			if (flag == 2) n = 0;
			break;
		}
		//����� ����������
		case 53:
		{
			MassEngine->Find(MassEngine, n);
			break;
		}
		//���������� �����
		case 54:
		{
			CreateFile(MassEngine, n);
			break;
		}
		//�������� �����
		case 55:
			n = OpenFile(MassEngine);
			break;
		case 56:
			DeleteFile();
			break;
		}
	}
}



