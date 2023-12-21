#pragma once
#include "GeneralFunction.h"

using namespace std;

class ISort {  //базовый класс
protected:
public:
	/// <summary>
	/// Сортировка вставками
	/// </summary>
	/// <param name="array">массив данных</param>
	/// <param name="rows">строки</param>
	/// <param name="columns">столбцы</param>
	virtual void Sort(int** array, int rows, int columns) = 0;
	virtual ~ISort() = default; //virtual - используется для освобождения ресурсов, используемых объектом производного класса, когда он удаляется из памяти.
};

class InsertSort : public ISort { //производный класс
public:
	/// <summary>
	/// Сортировка вставками
	/// </summary>
	/// <param name="array">массив</param>
	/// <param name="rows">строки</param>
	/// <param name="columns">столбцы</param>
	void Sort(int** array, int rows, int columns) override;
};
