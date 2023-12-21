#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //Для работы с Istringstream необходимо подключить заголовочный файл <sstream>. 
#include <limits>
#include <io.h>
#include <regex>

using namespace std;

int CheckInt();
string ReadStringWithoutWhitespace();
bool File_Exists(string fileName);
bool Only_Read(string fileName);
bool IsValidFilename(const string& fileName);
string getFilename(const string path);
bool IsReservedFileName(string fileName);
void CopyArray(int** copyArray, int** array, int rows, int columns);
void PrintArray(int** array, int rows, int columns);