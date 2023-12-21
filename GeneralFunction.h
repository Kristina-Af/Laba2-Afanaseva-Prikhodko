#pragma once
#include <iostream>//чтение и запись потока данных
#include <fstream> //определение нескольких классов, поддерживающих операции iostreams для последовательностей, хранящихся во внешних файлах
#include <string> //работа со строками
#include <sstream> //для работы с Istringstream необходимо подключить заголовочный файл <sstream>. 
#include <limits> //информация о различных характеристиках числовых типов данных
#include <io.h> //для работы с вводом и выводом
#include <regex> //для работы с регулярными выражениями, это шаблоны используемые для поиска и обработки текстовой информации

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