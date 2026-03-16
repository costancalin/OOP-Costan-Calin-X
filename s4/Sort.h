#pragma once
#include <initializer_list>

class Sort
{
	int* numbers;
	int length;

public:
	Sort(int count, int min_val, int max_val);
	Sort(std::initializer_list<int> init_list);
	Sort(int* vector, int count);
	Sort(int count, ...);
	Sort(const char* string_list);

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);

	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);

private:
	void InternalQuickSort(int low, int high, bool ascendent);
	int Partition(int low, int high, bool ascendent);
};