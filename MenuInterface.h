#pragma once
#include "ISort.h"

using namespace std;

enum PrintMetod { StartProgramm = 1, StartModuleTests = 2, StopProgramm = 3 };
enum InputMethod { FromFile = 1, ManualMethod = 2, RandomMethod = 3, ReturnMenu = 4 };
enum CreatingAFile { CreateFile = 1, ContunueWithoutCreatingFile = 2 };

void ShowGreeting();
void InputMethodMenu();
void CompleteControlWork(int** array, int strings, int columns);
void StartProgram();