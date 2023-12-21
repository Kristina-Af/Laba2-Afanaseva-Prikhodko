#pragma once
#include <iostream>//чтение и запись потока данных
#include <fstream> //определение нескольких классов, поддерживающих операции iostreams для последовательностей, хранящихся во внешних файлах
#include <string> //работа со строками
#include <sstream> //для работы с Istringstream необходимо подключить заголовочный файл <sstream>. 
#include <limits> //информация о различных характеристиках числовых типов данных
#include <io.h> //для работы с вводом и выводом
#include <regex> //для работы с регулярными выражениями, это шаблоны используемые для поиска и обработки текстовой информации

using namespace std;

/// <summary>
/// проверка на тип данных
/// </summary>
/// <returns>флаг проверки на тип данных</returns>
int CheckInt();

/// <summary>
/// проверка на пустой ввод
/// </summary>
/// <returns>флаг проверки на пустой ввод</returns>
string ReadStringWithoutWhitespace();

/// <summary>
/// Проверка файла на существование
/// </summary>
/// <param name="fileName">имя файла</param>
/// <returns>флаг проверки файла на существование</returns>
bool FileExists(string fileName);

/// <summary>
/// Чтение из файла 
/// </summary>
/// <param name="fileName">имя файла</param>
/// <returns>флаг чтения из файла</returns>
bool OnlyRead(string fileName);

/// <summary>
/// Проверка на допустимые имена
/// </summary>
/// <param name="fileName">имя файла</param>
/// <returns>флаг проверки имени</returns>
bool IsValidFileName(const string& fileName);

/// <summary>
/// Полученние имени файла
/// </summary>
/// <param name="path">путь</param>
/// <returns>флаг получения имени файла</returns>
string GetFileName(const string path);

/// <summary>
/// Проверка на зарезервированные имена
/// </summary>
/// <param name="fileName">имя файла</param>
/// <returns>флаг проверки на зарезервированные имена</returns>
bool IsReservedFileName(string fileName);

/// <summary>
/// Копирование массива
/// </summary>
/// <param name="copyArray">массив для сравнения</param>
/// <param name="array">массив</param>
/// <param name="rows">строки</param>
/// <param name="columns">столбцы</param>
void CopyArray(int** copyArray, int** array, int rows, int columns);

/// <summary>
/// Печать массива
/// </summary>
/// <param name="array">массив</param>
/// <param name="rows">строки</param>
/// <param name="columns">столбцы</param>
void PrintArray(int** array, int rows, int columns);