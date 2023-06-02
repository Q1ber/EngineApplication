#pragma once
#include <string>
//����� ����������
class Engine
{
	std::string Name;    //���
	std::string Type;    //���
	std::string Power;   //��������
	std::string Voltage; //����������
	std::string Current; //���
	std::string RPM;     //�������
	std::string EFF;     //���
	std::string Mass;    //�����

public:
	void Header(int i, std::string NameHeader);                          //������� ���������� ��� ��������
	std::string Change(std::string Name, bool flag);                     //������� ��� ������ ��������
	std::string Select(std::string var1, std::string var2);              //������� ��� ������ ����
	std::string Get(int n);                                              //������� �������� �������� �� private
	void Add();                                                          //������� ���������� ���������
	int Cout(Engine engine[], int n, std::string NameHeader,int flag);   //������� ������ ���������
	void Edit(Engine engine);                                            //������� �������������� ���������
	void Find(Engine engine[],int n);                                    //������� ��� ������ ����������
};
