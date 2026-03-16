#include "Sort.h"
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

Sort::Sort(int count, int min_val, int max_val)
{
	this->length = count;
	this->numbers = new int[count];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < count; i++)
	{
		this->numbers[i] = min_val + (rand() % (max_val - min_val + 1));
	}
}

Sort::Sort(std::initializer_list<int> init_list)
{
	this->length = (int)init_list.size();
	this->numbers = new int[this->length];
	int index = 0;
	for (int x : init_list)
	{
		this->numbers[index++] = x;
	}
}

Sort::Sort(int* vector, int count)
{
	this->length = count;
	this->numbers = new int[count];
	for (int i = 0; i < count; i++)
	{
		this->numbers[i] = vector[i];
	}
}

Sort::Sort(int count, ...)
{
	this->length = count;
	this->numbers = new int[count];
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		this->numbers[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* string_list)
{
	int count = 0;
	for (int i = 0; string_list[i] != '\0'; i++)
	{
		if (string_list[i] == ',') count++;
	}
	count++;
	this->length = count;
	this->numbers = new int[count];

	char* copy = new char[strlen(string_list) + 1];
	strcpy(copy, string_list);
	char* token = strtok(copy, ",");
	int index = 0;
	while (token != NULL)
	{
		this->numbers[index++] = atoi(token);
		token = strtok(NULL, ",");
	}
	delete[] copy;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->length; i++)
	{
		int key = this->numbers[i];
		int j = i - 1;
		while (j >= 0 && ((ascendent && this->numbers[j] > key) || (!ascendent && this->numbers[j] < key)))
		{
			this->numbers[j + 1] = this->numbers[j];
			j--;
		}
		this->numbers[j + 1] = key;
	}
}

int Sort::Partition(int low, int high, bool ascendent)
{
	int pivot = this->numbers[high];
	int i = (low - 1);
	for (int j = low; j < high; j++)
	{
		if ((ascendent && this->numbers[j] < pivot) || (!ascendent && this->numbers[j] > pivot))
		{
			i++;
			int temp = this->numbers[i];
			this->numbers[i] = this->numbers[j];
			this->numbers[j] = temp;
		}
	}
	int temp = this->numbers[i + 1];
	this->numbers[i + 1] = this->numbers[high];
	this->numbers[high] = temp;
	return (i + 1);
}

void Sort::InternalQuickSort(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int pi = Partition(low, high, ascendent);
		InternalQuickSort(low, pi - 1, ascendent);
		InternalQuickSort(pi + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	InternalQuickSort(0, this->length - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < this->length - 1; i++)
	{
		for (int j = 0; j < this->length - i - 1; j++)
		{
			if ((ascendent && this->numbers[j] > this->numbers[j + 1]) || (!ascendent && this->numbers[j] < this->numbers[j + 1]))
			{
				int temp = this->numbers[j];
				this->numbers[j] = this->numbers[j + 1];
				this->numbers[j + 1] = temp;
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->length; i++)
	{
		cout << this->numbers[i] << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return this->length;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < this->length)
	{
		return this->numbers[index];
	}
	return -1;
}