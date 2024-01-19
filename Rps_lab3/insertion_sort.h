#ifndef COMB_SORT_H
#define COMB_SORT_H

#include <vector>


/// <summary>
/// Класс, реализующий сортировку вставками.
/// </summary>
class InsertSort {
public:
    /// <summary>
    /// Сортирует вектор с использованием сортировки вставками.
    /// </summary>
    /// <param name="array">Вектор, который нужно отсортировать.</param>
    void sort(std::vector<int> &array);
};


#endif