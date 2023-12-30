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
			int finalSize = 0;
			int initialSize = 0;
			int* initialArray = nullptr;
			int* finalArray = nullptr;
			int* sortedArray = nullptr;
			InsertSort c;
			initial.open(initialPaths[t]);
			final.open(finalPaths[t]);
			int input = 0;

			while (!initial.eof()) {
				if ((input = initial.get()) == '\n' || input == EOF) { initialSize += 1; }
			}

			initial.clear();
			initial.seekg(0);
			getline(initial, temp);
			istringstream stream(temp);

			initial.clear();
			initial.seekg(0);
			initialArray = new int[initialSize];

			final >> finalSize;

			finalArray = new int[finalSize];

			sortedArray = new int[initialSize];

			if (initialSize != finalSize) {
				cout << "Количество чисел в " << initialPaths[t] << " не соответствует количеству чисел " << finalPaths[t] << endl;
				completeTests = false;
			}
			else {
				for (int i = 0; i < initialSize; i++) {
					initial >> initialArray[i];
				}

				for (int i = 0; i < finalSize; i++) {
					final >> finalArray[i];
				}

				CopyArray(sortedArray, initialArray, initialSize);
				c.Sort(sortedArray, initialSize);

				for (int i = 0; i < initialSize; i++) {
					if (sortedArray[i] != finalArray[i]) {
						insertCorrect = false;
					}
				}

				if (!insertCorrect) {
					completeTests = false;
					cout << "Сортировка вставками работает некорректно." << endl;
					cout << "Полученный массив:" << endl;
					PrintArray(sortedArray, initialSize);
					cout << "Ожидаемый массив:" << endl;
					PrintArray(finalArray, initialSize);
				}

				CopyArray(sortedArray, initialArray, initialSize);
			}

			for (int i = 0; i < initialSize; i++) {
				delete[] initialArray;
				initialArray = nullptr;
			}

			for (int i = 0; i < initialSize; i++) {
				delete[] sortedArray;
				sortedArray = nullptr;
			}

			for (int i = 0; i < finalSize; i++) {
				delete[] finalArray;
				finalArray = nullptr;
			}
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