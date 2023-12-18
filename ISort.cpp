#include "ISort.h"

using namespace std;

// Сортировка вставками
void InsertSort::Sort(int** array, int strings, int columns) {
	for (int i = 0; i < strings; i++) {
		for (int j = 0; j < columns - 1; j++) {
			for (int k = j + 1; k > 0; k--) {
				if (array[i][k] < array[i][k - 1]) {
					swap(array[i][k], array[i][k - 1]);
				}
			}
		}
	}
}