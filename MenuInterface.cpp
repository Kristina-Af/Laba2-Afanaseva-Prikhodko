#include "MenuInterface.h"
#include "ModuleTests.h"

using namespace std;

void ShowGreeting()
{
	system("cls");
	cout << "\t" << endl
		<< "���������� �������� ������������� � ��������� ����� ���������" << endl
		<< "425 ������, 2 ����" << endl
		<< "�������: 14 ���������� ��������� / Insertion sort" << endl
		<< "------------------------------------------------------------------" << endl;
	cout << "������� ������������ ��� �����:" << endl << "1 - ������ ������ ���������." << endl << "2 - ��������� ��������� �����." << endl
		<< "3 - ��������� ������ ���������" << endl << ">> ";
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
	int* tmp = nullptr; //nullptr - ��������� �������� ���������
	int** array = nullptr;
	ifstream file;
	int choseMethod = 0;
	do {
		cout << "�������� ������ ����� ������:" << endl << "1 - ���������� ������� �� �����." << endl
			<< "2 - ���������� ������� �������." << endl << "3 - ���������� ������� ���������� ������� � ��������� �� -100 �� 100." << endl
			<< "4 - ����� � ������� ���� ���������." << endl << ">> ";
		choseMethod = CheckInt();
		switch (choseMethod) {
		case FromFile:
			cout << "������� ���� �����:" << endl << "> ";
			path = ReadStringWithoutWhitespace();
			while (!File_Exists(path)) {
				cout << "������ ��� �������� �����! ���������� ������ ���� �����." << endl << "> ";
				path = ReadStringWithoutWhitespace();
			}
			file.open(path);
			cout << "���� ������� ������!" << endl;
			if (file.peek() == ifstream::traits_type::eof()) { //traits_type - ���� ����������� ��������� � ��������������� �������� �����, eof - ����� ������, ���� ���� ����, � ���� ���� �� ����, �� ������� ����
				cout << "���� ����. ��������� ���� � ���������� ��� ���." << endl;
			}
			else {
				while (!file.eof()) {
					file >> intTmp;
					if (file.fail()) { //�������� ������ ��� ������ �����
						file.clear();
						fileIsCorrect = false;
						break;
					}
				}
				file.clear();
				file.seekg(0);
				while (!file.eof()) {
					if ((input = file.get()) == '\n' || input == EOF) { rows += 1; } //eof - ���������� ��������� ��������
				}
				file.clear();
				file.seekg(0); //file.seekg - ��������� ������ ������������ ������� � �����.
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
					cout << "� ����� ���������� ����������� ����������� �������. ��������� ���� � ���������� ��� ���." << endl;
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
			cout << "������� ������ �������: ";
			rows = CheckInt();
			while (rows < 1) {
				cout << "���������� ����� �� ����� ���� ������ ����. ���������� ������ ������ �����." << endl;
				rows = CheckInt();
			}
			columns = rows;

			array = new int* [rows];
			for (int i = 0; i < rows; i++) {
				array[i] = new int[columns];
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					cout << "���� " << i + 1 << " ������ " << j + 1 << " �������." << endl;
					array[i][j] = CheckInt();
				}
			}
			CompleteControlWork(array, rows, columns);
			choseMethod = ReturnMenu;
			break;
		case RandomMethod:
			cout << "������� ���������� ����� �������: ";
			rows = CheckInt();
			while (rows < 1) {
				cout << "���������� ����� �� ����� ���� ������ ����. ���������� ������ ������ �����." << endl;
				rows = CheckInt();
			}
			cout << "������� ���������� �������� �������: ";
			columns = CheckInt();
			while (columns < 1) {
				cout << "���������� �������� �� ����� ���� ������ ����. ���������� ������ ������ �����." << endl;
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
			cout << "������ ������ ��� � ����, ���������� ��� ���" << endl;
			break;
		}
		if (choseMethod != ReturnMenu) system("pause");
	} while (choseMethod != ReturnMenu);
}

void CompleteControlWork(int** array, int rows, int columns) {
	int** copyarray = nullptr; //�������� ���������� ������� � �������
	copyarray = new int* [rows];
	for (int i = 0; i < rows; i++) {
		copyarray[i] = new int[columns];
	}
	cout << endl << "�������� ������:" << endl;
	PrintArray(array, rows, columns);
	cout << endl << "���������� ���������:" << endl;
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
			cout << "������ ������ ��� � ����, ���������� ��� ���" << endl;
			break;
		}
		if (UserChoise != StopProgramm)	system("pause");
	} while (UserChoise != StopProgramm);
}