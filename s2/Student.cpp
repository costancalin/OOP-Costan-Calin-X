#include "Student.h"
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


void Student::setnume(const char* a)
{
	this->nume=a;
}
const char* Student::getnume()
{
	return this->nume;
}

void Student::setmate(int x)
{
	this->mate = x;
}
int Student::getmate()
{
	return this->mate;
}

void Student::setengleza(int x)
{
	this->engleza = x;
}
int Student::getengleza()
{
	return this->engleza;
}

void Student::setistorie(int x)
{
	this->istorie = x;
}
int Student::getistorie()
{
	return this->istorie;
}

double Student::getmedie()
{
	return double((this->istorie + this->mate + this->engleza) / 3.0);
}
