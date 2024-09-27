#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

int CheckInt();
double CheckDouble();
void PrintArray(vector<double>& arr);
bool IsReservedName(string path);
string EnteringPathToFile();
fstream OpenFile();