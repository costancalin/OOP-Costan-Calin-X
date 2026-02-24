#include "globals.h"
#include "Student.h"
#include <iostream>
#include <string.h>

using namespace std;

int compname(Student a, Student b)
{
	if (strcmp(a.getnume(), b.getnume()) < 0)
		return -1;
	else
		if (strcmp(a.getnume(), b.getnume()) == 0)
			return 0;
		else
			return 1;

}

int compmate(Student a, Student b)
{
	if (a.getmate() < b.getmate())
		return -1;
	else
		if (a.getmate() == b.getmate())
			return 0;
		else
			return 1;

}

int compengleza(Student a, Student b)
{
	if (a.getengleza() < b.getengleza())
		return -1;
	else
		if (a.getengleza() == b.getengleza())
			return 0;
		else
			return 1;

}
int compistorie(Student a, Student b)
{
	if (a.getistorie() < b.getistorie())
		return -1;
	else
		if (a.getistorie() == b.getistorie())
			return 0;
		else
			return 1;

}

int compmedie(Student a, Student b)
{
	if (a.getmedie() < b.getmedie())
		return -1;
	else
		if (a.getmedie() == b.getmedie())
			return 0;
		else
			return 1;

}