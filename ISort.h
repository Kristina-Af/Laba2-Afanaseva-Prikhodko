#pragma once
#include "GeneralFunction.h"

using namespace std;

class ISort {  //базовый класс
protected:
public:
	virtual void Sort(int** array, int strings, int columns) = 0;
	virtual ~ISort() = default; //virtual - используется для освобождения ресурсов, используемых объектом производного класса, когда он удаляется из памяти.
};

class InsertSort : public ISort { //производный класс
public:
	void Sort(int** array, int strings, int columns) override;
};
