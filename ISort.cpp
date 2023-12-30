#include "ISort.h"

using namespace std;

void InsertSort::Sort(int* array, int size) {
    int tmp, // временная переменная для хранения значения элемента сортируемого массива
        item; // индекс предыдущего элемента
    for (int i = 0; i < size; i++)
    {
        tmp = array[i]; // инициализируем временную переменную текущим значением элемента массива
        item = i - 1; // запоминаем индекс предыдущего элемента массива
        while (item >= 0 && array[item] > tmp)
        {
            array[item + 1] = array[item];
            array[item] = tmp;
            item--;
        }

    }
}