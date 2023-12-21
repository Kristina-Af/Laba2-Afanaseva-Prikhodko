#include "moduletests.h"
#define NumberOfTests 5

using namespace std;

void CompleteModuleTests() {
	ifstream initial, final;
	bool completeTests = true;
	bool filesExists = true;
	string initialPaths[NumberOfTests] = { "AB_1.txt", "AB_2.txt", "AB_3.txt", "AB_4.txt", "AB_5.txt" };
	string finalPaths[NumberOfTests] = { "ABC_1.txt", "ABC_2.txt", "ABC_3.txt", "ABC_4.txt", "ABC_5.txt" };

	for (int i = 0; i < NumberOfTests; i++) {
		if (!FileExists(initialPaths[i]) || !FileExists(finalPaths[i])) {
			filesExists = false;
		}
	}

	if (filesExists) {
		for (int t = 0; t < NumberOfTests; t++) {
			string temp;
			string value;
			bool insertCorrect = true;
			int finalRows = 0, finalColumns = 0;
			int initialRows = 0, initialColumns = 0;
			int** initialArray = nullptr;
			int** finalArray = nullptr;
			int** sortedArray = nullptr;
			InsertSort c;
			initial.open(initialPaths[t]);
			final.open(finalPaths[t]);
			int input = 0;

			while (!initial.eof()) {
				if ((input = initial.get()) == '\n' || input == EOF) { initialRows += 1; }
			}

			initial.clear();
			initial.seekg(0);
			getline(initial, temp);
			istringstream stream(temp);

			while (stream >> value) {
				initialColumns++;
			}

			initial.clear();
			initial.seekg(0);
			initialArray = new int* [initialRows];

			for (int i = 0; i < initialRows; i++) {
				initialArray[i] = new int[initialColumns];
			}

			final >> finalRows;
			final >> finalColumns;
			finalArray = new int* [finalRows];

			for (int i = 0; i < finalRows; i++) {
				finalArray[i] = new int[finalColumns];
			}

			sortedArray = new int* [initialRows];

			for (int i = 0; i < initialRows; i++) {
				sortedArray[i] = new int[initialColumns];
			}

			if (initialRows != finalRows || initialColumns != finalColumns) {
				cout << "Количество строк или столбцов матрицы в " << initialPaths[t] << " не соответствует количеству строк или столбцов " << finalPaths[t] << endl;
				completeTests = false;
			}
			else {
				for (int i = 0; i < initialRows; i++) {
					for (int j = 0; j < initialColumns; j++) {
						initial >> initialArray[i][j];
					}
				}

				for (int i = 0; i < finalRows; i++) {
					for (int j = 0; j < finalColumns; j++) {
						final >> finalArray[i][j];
					}
				}

				CopyArray(sortedArray, initialArray, initialRows, initialColumns);
				c.Sort(sortedArray, initialRows, initialColumns);

				for (int i = 0; i < initialRows; i++) {
					for (int j = 0; j < initialColumns; j++) {
						if (sortedArray[i][j] != finalArray[i][j]) {
							insertCorrect = false;
						}
					}
				}

				if (!insertCorrect) {
					completeTests = false;
					cout << "Сортировка вставками работает некорректно." << endl;
					cout << "Полученный массив:" << endl;
					PrintArray(sortedArray, initialRows, initialColumns);
					cout << "Ожидаемый массив:" << endl;
					PrintArray(finalArray, initialRows, initialColumns);
				}
				CopyArray(sortedArray, initialArray, initialRows, initialColumns);
			}

			for (int i = 0; i < initialRows; i++) {
				delete[] initialArray[i];
				initialArray[i] = nullptr;
			}

			delete[] initialArray;
			initialArray = nullptr;

			for (int i = 0; i < initialRows; i++) {
				delete[] sortedArray[i];
				sortedArray[i] = nullptr;
			}

			delete[] sortedArray;
			sortedArray = nullptr;

			for (int i = 0; i < finalRows; i++) {
				delete[] finalArray[i];
				finalArray[i] = nullptr;
			}

			delete[] finalArray;
			finalArray = nullptr;
			final.close();
			initial.close();
		}
		if (completeTests) {
			cout << "Все тесты прошли успешно!" << endl;
		}
	}
	else {
		cout << "Не обнаружено файлов для проведения модульных тестов! Файлы должны называться: начальные данные - AB_1-AB_5, конечные - ABC_1-ABC_5" << endl;
	}
}