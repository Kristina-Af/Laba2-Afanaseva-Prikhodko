#pragma once
#include "GeneralFunction.h"

using namespace std;

class ISort {
protected:
public:
	virtual void Sort(int** array, int strings, int columns) = 0;
	virtual ~ISort() = default;
};

class InsertSort : public ISort {
public:
	void Sort(int** array, int strings, int columns) override;
};