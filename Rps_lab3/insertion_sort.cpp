#include "insertion_sort.h"


void InsertSort::sort(std::vector<int> &array) {
    int tmp{}, // временная переменная для хранения значения элемента сортируемого массива
        item{}; // индекс предыдущего элемента
    for (int i = 0; i < array.size(); i++) {
        tmp = array[i]; // инициализируем временную переменную текущим значением элемента массива
        item = i - 1; // запоминаем индекс предыдущего элемента массива

        while (item >= 0 && array[item] > tmp) {
            array[item + 1] = array[item];
            array[item] = tmp;
            item--;
        }
    }
}
