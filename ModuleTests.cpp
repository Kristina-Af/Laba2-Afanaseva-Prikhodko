#include "moduletests.h"
#define NumberOfTests 5

using namespace std;

void CompleteModuleTests() {
	ifstream initial, final;
	bool CompleteTests = true;
	bool FilesExists = true;
	string initialPaths[NumberOfTests] = { "AB_1.txt", "AB_2.txt", "AB_3.txt", "AB_4.txt", "AB_5.txt" };
	string finalPaths[NumberOfTests] = { "ABC_1.txt", "ABC_2.txt", "ABC_3.txt", "ABC_4.txt", "ABC_5.txt" };

	for (int i = 0; i < NumberOfTests; i++) {
		if (!File_Exists(initialPaths[i]) || !File_Exists(finalPaths[i])) {
			FilesExists = false;
		}
	}

	if (FilesExists) {
		for (int t = 0; t < NumberOfTests; t++) {
			string temp;
			string value;
			bool InsertCorrect = true;
			int finalStrings = 0, finalColumns = 0;
			int initialStrings = 0, initialColumns = 0;
			int** initialArray = nullptr;
			int** finalArray = nullptr;
			int** sortedArray = nullptr;
			InsertSort c;
			initial.open(initialPaths[t]);
			final.open(finalPaths[t]);
			int input = 0;
			while (!initial.eof()) {
				if ((input = initial.get()) == '\n' || input == EOF) { initialStrings += 1; }
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
			initialArray = new int* [initialStrings];
			for (int i = 0; i < initialStrings; i++) {
				initialArray[i] = new int[initialColumns];
			}
			final >> finalStrings;
			final >> finalColumns;
			finalArray = new int* [finalStrings];
			for (int i = 0; i < finalStrings; i++) {
				finalArray[i] = new int[finalColumns];
			}
			sortedArray = new int* [initialStrings];
			for (int i = 0; i < initialStrings; i++) {
				sortedArray[i] = new int[initialColumns];
			}
			if (initialStrings != finalStrings || initialColumns != finalColumns) {
				cout << "���������� ����� ��� �������� ������� � " << initialPaths[t] << " �� ������������� ���������� ����� ��� �������� " << finalPaths[t] << endl;
				CompleteTests = false;
			}
			else {
				for (int i = 0; i < initialStrings; i++) {
					for (int j = 0; j < initialColumns; j++) {
						initial >> initialArray[i][j];
					}
				}
				for (int i = 0; i < finalStrings; i++) {
					for (int j = 0; j < finalColumns; j++) {
						final >> finalArray[i][j];
					}
				}
				CopyArray(sortedArray, initialArray, initialStrings, initialColumns);
				c.Sort(sortedArray, initialStrings, initialColumns);
				for (int i = 0; i < initialStrings; i++) {
					for (int j = 0; j < initialColumns; j++) {
						if (sortedArray[i][j] != finalArray[i][j]) {
							InsertCorrect = false;
						}
					}
				}
				if (!InsertCorrect) {
					CompleteTests = false;
					cout << "���������� ��������� �������� �����������." << endl;
					cout << "���������� ������:" << endl;
					PrintArray(sortedArray, initialStrings, initialColumns);
					cout << "��������� ������:" << endl;
					PrintArray(finalArray, initialStrings, initialColumns);
				}
				CopyArray(sortedArray, initialArray, initialStrings, initialColumns);
			}
			for (int i = 0; i < initialStrings; i++) {
				delete[] initialArray[i];
				initialArray[i] = nullptr;
			}
			delete[] initialArray;
			initialArray = nullptr;
			for (int i = 0; i < initialStrings; i++) {
				delete[] sortedArray[i];
				sortedArray[i] = nullptr;
			}
			delete[] sortedArray;
			sortedArray = nullptr;
			for (int i = 0; i < finalStrings; i++) {
				delete[] finalArray[i];
				finalArray[i] = nullptr;
			}
			delete[] finalArray;
			finalArray = nullptr;
			final.close();
			initial.close();
		}
		if (CompleteTests) {
			cout << "��� ����� ������ �������!" << endl;
		}
	}
	else {
		cout << "�� ���������� ������ ��� ���������� ��������� ������! ����� ������ ����������: ��������� ������ - AB_1-AB_5, �������� - ABC_1-ABC_5" << endl;
	}
}