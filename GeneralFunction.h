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
bool File_Exists(string FileName);
bool Only_Read(string FileName);
bool IsValidFilename(const string& filename);
string getFilename(const string path);
bool IsReservedFileName(string FileName);
void CopyArray(int** copyarray, int** array, int strings, int columns);
void PrintArray(int** array, int strings, int columns);