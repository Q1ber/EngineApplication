#include "Find.h"
#include "ClassEngine.h"
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string>

using namespace std;

void Head(Engine MassEngine, int i)
{
	system("cls");
	cout << "-----------------------Запись №" << i + 1 << "--------------------------" << endl;
	MassEngine.Cout();
	system("pause");
}

void FindName(Engine MassEngine,string UserSearch,int key,int i)
{
	if (MassEngine.GetVar(key) == UserSearch) Head(MassEngine, i);

}

void FindNumber(Engine MassEngine,int UserSearchNum,int key,int position,int i)
{

	int ValueEngine = 0;

	ValueEngine = stoi(MassEngine.GetVar(key));

	if (position == 49) if (ValueEngine == UserSearchNum)Head(MassEngine, i);
	if (position == 50) if (ValueEngine > UserSearchNum) Head(MassEngine, i);
	if (position == 51) if (ValueEngine < UserSearchNum) Head(MassEngine, i);
		
}
