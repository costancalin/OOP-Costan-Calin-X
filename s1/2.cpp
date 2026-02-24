#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	printf("introduceti propozitia : ");
	char s[100], * cuv[100], * p;

	fgets(s, sizeof(s), stdin);
	s[strlen(s) - 1] = '\0';

	int n = 0;
	p = strtok(s, " ");

	while (p != NULL)
	{
		cuv[n++] = p;
		p = strtok(NULL, " ");
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strlen(cuv[i]) < strlen(cuv[j]) || (strlen(cuv[i]) == strlen(cuv[j]) && strcmp(cuv[i], cuv[j]) > 0))
			{
				char* aux = cuv[i];
				cuv[i] = cuv[j];
				cuv[j] = aux;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", cuv[i]);
	}

	return 0;
}