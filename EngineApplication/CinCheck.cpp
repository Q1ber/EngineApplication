#include "CinCheck.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
//������� �������� ����� �� ������� ��������
string CinCheck(string Name) 
{
    int Value = 0;
    string StringValue;

    while (true)
    {
        cin >> Name;

        //�������� ���������� ����� ���������� � ���������� �� ������
        try
        {
            Value = stoi(Name);
        }
        catch (std::invalid_argument)
        {
            //�������, ��� ����� ������� ������ �����
            cout << "�������� ���� ������ �����!\n";
        }
        catch (std::out_of_range)
        {
            //�������, ��� ����� ������� �������
            cout << "������� ������� �����! \n";
        }
        catch (...)
        {
            //���� ����� ��������� �����-�� ����������, ������� �� ���������� ����, �� �������, ��� �������� ����������� ������
            cout << "������! \n";
        }

        if (Value > 0)
        {
            //�������������� ����� � ������ � ������� �
            StringValue = std::to_string(Value);
            return StringValue;
        }
        else
        {
            cout << "���������� ��� ���! \n";
        }
    }
}
