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

/// <summary>
/// Проверка файла
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool FileExists(string fileName);

/// <summary>
/// Чтение из файла
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool OnlyRead(string fileName);

/// <summary>
/// Проверка на допустимые имена
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool IsValidFileName(const string& fileName);

/// <summary>
/// Полученние имени файла
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
string GetFileName(const string path);

/// <summary>
/// Проверка на зарезервированные имена
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool IsReservedFileName(string fileName);

/// <summary>
/// Копирование массива
/// </summary>
/// <param name="copyArray"></param>
/// <param name="array"></param>
/// <param name="rows"></param>
/// <param name="columns"></param>
void CopyArray(int** copyArray, int** array, int rows, int columns);

/// <summary>
/// Печать массива
/// </summary>
/// <param name="array"></param>
/// <param name="rows"></param>
/// <param name="columns"></param>
void PrintArray(int** array, int rows, int columns);