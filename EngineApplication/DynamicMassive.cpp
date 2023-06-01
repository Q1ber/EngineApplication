#include "DynamicMassive.h"
#include <iostream>
#include <string>

using namespace std;

DynamicMassive::DynamicMassive(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

DynamicMassive::~DynamicMassive()
{
	delete[] arr;
}

void DynamicMassive::push(string Text)
{

}

int DynamicMassive::pop()
{
	return 0;
}

int DynamicMassive::size()
{
	return 0;
}

bool DynamicMassive::isEmpty()
{
	return false;
}

bool DynamicMassive::isFull()
{
	return false;
}
