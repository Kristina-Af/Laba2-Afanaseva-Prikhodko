#pragma once
#include "GeneralFunction.h"

using namespace std;

class ISort {  //базовый класс
protected:
public:
	/// <summary>
	/// Сортировка вставками
	/// </summary>
	/// <param name="array"></param>
	/// <param name="strings"></param>
	/// <param name="columns"></param>
	virtual void Sort(int** array, int rows, int columns) = 0;
	virtual ~ISort() = default; //virtual - используется для освобождения ресурсов, используемых объектом производного класса, когда он удаляется из памяти.
};

class InsertSort : public ISort { //производный класс
public:
	/// <summary>
	/// Сортировка вставками
	/// </summary>
	/// <param name="array"></param>
	/// <param name="strings"></param>
	/// <param name="columns"></param>
	void Sort(int** array, int rows, int columns) override;
};
