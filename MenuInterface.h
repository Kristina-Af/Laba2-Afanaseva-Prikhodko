#pragma once
#include "ISort.h"
#include "Enum.h"
using namespace std;

/// <summary>
/// трансляция основной информии
/// </summary>
void ShowGreeting();

/// <summary>
/// выбор заполнения массива
/// </summary>
void InputMethodMenu();

/// <summary>
/// Функция выполнения контрольной работы
/// </summary>
/// <param name="array">массив</param>
/// <param name="rows">строки</param>
/// <param name="columns">столбцы</param>
void CompleteControlWork(int* array, int size);

/// <summary>
/// начало программы
/// </summary>
void StartProgram();