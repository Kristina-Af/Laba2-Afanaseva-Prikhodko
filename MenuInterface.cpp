#include "MenuInterface.h"
#include "ModuleTests.h"

using namespace std;

void ShowGreeting()
{
	system("cls");
	cout << "\t" << endl
		<< "Афанасьева Кристина Александровна и Приходько Алена Андреевна" << endl
		<< "425 группа, 2 курс" << endl
		<< "Вариант: 14 Сортировка вставками / Insertion sort" << endl
		<< "------------------------------------------------------------------" << endl;
	cout << "Выберие интересующий вас пункт:" << endl << "1 - Начать работу программы." << endl << "2 - Выполнить модульные тесты." << endl
		<< "3 - Завершить работу программы" << endl << ">> ";
}


void InputMethodMenu() {
	bool fileIsCorrect = true;
	int rows = 0;
	int columns = 0;
	int input = 0;
	int intTmp;
	string temp;
	string path;
	string value;
	int* tmp = nullptr; //nullptr - константа нулевого указателя
	int** array = nullptr;
	ifstream file;
	int choseMethod = 0;
	do {
		cout << "Выберите способ ввода данных:" << endl << "1 - Заполнение массива из файла." << endl
			<< "2 - Заполнение массива вручную." << endl << "3 - Заполнение массива случайными числами в диапазоне от -100 до 100." << endl
			<< "4 - Выход в главное меню программы." << endl << ">> ";
		choseMethod = CheckInt();
		switch (choseMethod) {
		case FromFile:
			cout << "Введите путь файла:" << endl << "> ";
			path = ReadStringWithoutWhitespace();
			while (!File_Exists(path)) {
				cout << "Ошибка при открытии файла! Попробуйте ввести путь снова." << endl << "> ";
				path = ReadStringWithoutWhitespace();
			}
			file.open(path);
			cout << "Файл успешно открыт!" << endl;
			if (file.peek() == ifstream::traits_type::eof()) { //traits_type - дает возможность проверять и преобразовывать свойства типов, eof - выдаёт истину, если файл пуст, а если файл не пуст, то выдаётся ложь
				cout << "Файл пуст. Заполните файл и попробуйте еще раз." << endl;
			}
			else {
				while (!file.eof()) {
					file >> intTmp;
					if (file.fail()) { //проверка ошибки при чтении файла
						file.clear();
						fileIsCorrect = false;
						break;
					}
				}
				file.clear();
				file.seekg(0);
				while (!file.eof()) {
					if ((input = file.get()) == '\n' || input == EOF) { rows += 1; } //eof - возвращает ненулевое значение
				}
				file.clear();
				file.seekg(0); //file.seekg - позволяет искать произвольную позицию в файле.
				tmp = new int[rows];
				for (int i = 0; i < rows; i++) {
					tmp[i] = 0; 
					getline(file, temp);
					istringstream stream(temp);
					while (stream >> value) {
						tmp[i]++;
					}
					columns = tmp[i];
				}
				file.clear();
				file.seekg(0);
				for (int i = 0; i < rows - 1; i++) {
					if (tmp[i] != tmp[i + 1]) {
						fileIsCorrect = false;
					}
				}
				delete[] tmp;
				tmp = nullptr;
				if (!fileIsCorrect) {
					cout << "В файле содержится некорректно заполненная матрица. Исправьте файл и попробуйте еще раз." << endl;
					file.close();
					choseMethod = ReturnMenu;
					break;
				}
				array = new int* [rows];
				for (int i = 0; i < rows; i++) {
					array[i] = new int[columns];
				}
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < columns; j++) {
						file >> array[i][j];
					}
				}
				CompleteControlWork(array, rows, columns);
			}

			file.close();
			choseMethod = ReturnMenu;
			break;
		case ManualMethod:
			cout << "Введите размер массива: ";
			rows = CheckInt();
			while (rows < 1) {
				cout << "Количество строк не может быть меньше нуля. Попробуйте ввести другое число." << endl;
				rows = CheckInt();
			}
			columns = rows;

			array = new int* [rows];
			for (int i = 0; i < rows; i++) {
				array[i] = new int[columns];
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					cout << "Ввод " << i + 1 << " строки " << j + 1 << " столбца." << endl;
					array[i][j] = CheckInt();
				}
			}
			CompleteControlWork(array, rows, columns);
			choseMethod = ReturnMenu;
			break;
		case RandomMethod:
			cout << "Введите количество строк массива: ";
			rows = CheckInt();
			while (rows < 1) {
				cout << "Количество строк не может быть меньше нуля. Попробуйте ввести другое число." << endl;
				rows = CheckInt();
			}
			cout << "Введите количество столбцов массива: ";
			columns = CheckInt();
			while (columns < 1) {
				cout << "Количество столбцов не может быть меньше нуля. Попробуйте ввести другое число." << endl;
				columns = CheckInt();
			}

			array = new int* [rows];
			for (int i = 0; i < rows; i++) {
				array[i] = new int[columns];
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					array[i][j] = -100 + rand() % 201;
				}
			}
			CompleteControlWork(array, rows, columns);
			choseMethod = ReturnMenu;
			break;
		case ReturnMenu:
			break;
		default:
			cout << "Такого пункта нет в меню, попробуйте еще раз" << endl;
			break;
		}
		if (choseMethod != ReturnMenu) system("pause");
	} while (choseMethod != ReturnMenu);
}

void CompleteControlWork(int** array, int rows, int columns) {
	int** copyarray = nullptr; //передача двумерного массива в функцию
	copyarray = new int* [rows];
	for (int i = 0; i < rows; i++) {
		copyarray[i] = new int[columns];
	}
	cout << endl << "Исходный массив:" << endl;
	PrintArray(array, rows, columns);
	cout << endl << "Сортировка вставками:" << endl;
	CopyArray(copyarray, array, rows, columns);
	InsertSort c;
	c.Sort(copyarray, rows, columns);
	PrintArray(copyarray, rows, columns);
	cout << endl;
}


void StartProgram() {
	setlocale(LC_ALL, "RU");
	srand(static_cast<unsigned int>(time(NULL)));
	int UserChoise = 0;
	do {
		system("cls");
		ShowGreeting();
		UserChoise = CheckInt();
		switch (UserChoise) {
		case StartProgramm:
			InputMethodMenu();
			break;
		case StartModuleTests:
			CompleteModuleTests();
			break;
		case StopProgramm:
			break;
		default:
			cout << "Такого пункта нет в меню, попробуйте еще раз" << endl;
			break;
		}
		if (UserChoise != StopProgramm)	system("pause");
	} while (UserChoise != StopProgramm);
}