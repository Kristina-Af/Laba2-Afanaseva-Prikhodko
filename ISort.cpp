#include "ISort.h"

using namespace std;

void InsertSort::Sort(int* array, int size) {
    int tmp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
        item; // ������ ����������� ��������
    for (int i = 0; i < size; i++)
    {
        tmp = array[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
        item = i - 1; // ���������� ������ ����������� �������� �������
        while (item >= 0 && array[item] > tmp)
        {
            array[item + 1] = array[item];
            array[item] = tmp;
            item--;
        }

    }
}