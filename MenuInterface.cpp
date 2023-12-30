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
	int size = 0;
	int input = 0;
	int intTmp;
	string temp;
	string path;
	string value;
	int* tmp = nullptr; //nullptr - константа нулевого указателя
	int* array = nullptr;
	ifstream file;
	int choseMethod = 0;

	do {
		cout << "Выберите способ ввода данных:" << endl << "1 - Заполнение массива из файла." << endl
			<< "2 - Заполнение массива вручную." << endl << "3 - Заполнение массива случайными числами в диапазоне от -100 до 100." << endl
			<< "4 - Выход в главное меню программы." << endl << ">> ";
		choseMethod = CheckInt();

		switch (choseMethod) {
		case FromFile:
			cout << "Введите путь файла:" << endl << ">> ";
			path = ReadStringWithoutWhitespace();

			while (!FileExists(path)) {
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
					if ((input = file.get()) == '\n' || input == EOF) { size += 1; } //eof - возвращает ненулевое значение
				}

				file.clear();
				file.seekg(0); //file.seekg - позволяет искать произвольную позицию в файле.
				tmp = new int[size];

				for (int i = 0; i < size; i++) {
					tmp[i] = 0;
					getline(file, temp);
					istringstream stream(temp); //istringstream - преобразование строк в поток данных

					while (stream >> value) {
						tmp[i]++;
					}
				}

				file.clear();
				file.seekg(0);

				for (int i = 0; i < size - 1; i++) {
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

				array = new int[size];

				for (int i = 0; i < size; i++) {
					file >> array[i];
				}

				CompleteControlWork(array, size);
			}

			file.close();
			choseMethod = ReturnMenu;
			break;

		case ManualMethod:
			cout << "Введите размер массива: ";
			size = CheckInt();
			while (size < 1) {
				cout << "Количество строк не может быть меньше нуля. Попробуйте ввести другое число." << endl;
				size = CheckInt();
			}

			array = new int[size];

			for (int i = 0; i < size; i++) {
				cout << "Ввод " << i + 1 << " числа " << endl;
				array[i] = CheckInt();
			}

			CompleteControlWork(array, size);
			choseMethod = ReturnMenu;
			break;

		case RandomMethod:
			cout << "Введите количество чисел массива: ";
			size = CheckInt();

			while (size < 1) {
				cout << "Количество чисел не может быть меньше нуля. Попробуйте ввести другое число." << endl;
				size = CheckInt();
			}

			array = new int[size];

			for (int i = 0; i < size; i++) {
				array[i] = -100 + rand() % 201;
			}
			CompleteControlWork(array, size);
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

void CompleteControlWork(int* array, int  size) {
	int* copyArray = nullptr; //передача одномерного массива в функцию
	copyArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		copyArray[i] = array[i];
	}

	cout << endl << "Исходный массив:" << endl;
	PrintArray(array, size);

	cout << endl << "Сортировка вставками:" << endl;
	InsertSort c;
	c.Sort(copyArray, size);
	PrintArray(copyArray, size);
	cout << endl;
}


void StartProgram() {
	setlocale(LC_ALL, "RU");
	srand(static_cast<unsigned int>(time(NULL)));
	int userChoise = 0;
	do {
		system("cls");
		ShowGreeting();
		userChoise = CheckInt();
		switch (userChoise) {

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
		if (userChoise != StopProgramm)	system("pause");
	} while (userChoise != StopProgramm);
}