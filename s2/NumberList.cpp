#include "NumberList.h"
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int a)
{
	if (this->count >= 10) return false;
	this->numbers[this->count] = a;
	this->count++;
}

void NumberList::Sort()
{
	for (int i = 0;i <= this->count - 1;i++)
		for (int j = i + 1;j <= this->count;j++)
			if (this->numbers[i] > this->numbers[j])
				swap(this->numbers[i], this->numbers[j]);
}

void NumberList::Print()
{
	for (int i = 1; i < this->count;i++)
		cout << numbers[i] << " ";

}
