#include "Sort.h"
#include <iostream>

using namespace std;

int main()
{
	Sort s1(10, 1, 50);
	cout << "Random: ";
	s1.Print();
	s1.InsertSort(true);
	cout << "Insert Asc: ";
	s1.Print();

	Sort s2 = { 5, 8, 2, 9, 1 };
	cout << "Init List: ";
	s2.Print();
	s2.BubbleSort(false);
	cout << "Bubble Desc: ";
	s2.Print();

	int v[] = { 10, 30, 20, 50, 40 };
	Sort s3(v, 5);
	cout << "Vector: ";
	s3.Print();
	s3.QuickSort(true);
	cout << "Quick Asc: ";
	s3.Print();

	Sort s4(4, 100, 200, 300, 400);
	cout << "Variadic: ";
	s4.Print();

	Sort s5("12,5,33,1,90");
	cout << "String: ";
	s5.Print();

	cout << "Count s5: " << s5.GetElementsCount() << endl;
	cout << "Index 2 in s5: " << s5.GetElementFromIndex(2) << endl;

	return 0;
}