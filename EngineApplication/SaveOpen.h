#pragma once
#include "ClassEngine.h"
#include <iostream>

using namespace std;

void CreateFile(Engine engine[], int n);
void WriteFile(Engine *engine, std::string Name, std::string line, int n);
int OpenFile(Engine *engine);
void DeleteFile();
