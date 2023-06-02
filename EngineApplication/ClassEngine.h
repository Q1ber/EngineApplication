#pragma once
#include <string>
//Класс двигателей
class Engine
{
	std::string Name;    //Имя
	std::string Type;    //Тип
	std::string Power;   //Мощность
	std::string Voltage; //Напряжение
	std::string Current; //Ток
	std::string RPM;     //Обороты
	std::string EFF;     //КПД
	std::string Mass;    //Масса

public:
	void Header(int i, std::string NameHeader);                          //Функция заголовока для удобства
	std::string Change(std::string Name, bool flag);                     //Функция для замены значения
	std::string Select(std::string var1, std::string var2);              //Функция для выбора типа
	std::string Get(int n);                                              //Функция возврата значения из private
	void Add();                                                          //Функция добавления двигателя
	int Cout(Engine engine[], int n, std::string NameHeader,int flag);   //Функция вывода двигателя
	void Edit(Engine engine);                                            //Функция редактирования двигателя
	void Find(Engine engine[],int n);                                    //Функция для поиска двигателей
};
