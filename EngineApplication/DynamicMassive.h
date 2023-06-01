#pragma once
#include <string>

#define SIZE 100

class DynamicMassive
{
	int* arr;
	int top;
	int capacity;

public:
	DynamicMassive(int size = SIZE);
	~DynamicMassive();
	void push(std::string);
	int pop();

	int size();
	bool isEmpty();
	bool isFull();
};

