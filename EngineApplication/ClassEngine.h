#pragma once
#include <string>

class Engine
{
	std::string Name;
	std::string Type;
	std::string Power;
	std::string Voltage;
	std::string Current;
	std::string RPM;
	std::string EFF;
	std::string Mass;

public:
	void Add();
	void Cout();
	void Edit();
	void Save();
	void Open();
	std::string GetVar(int n);
};
