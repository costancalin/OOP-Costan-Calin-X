#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int sum = 0;
int main()
{
	FILE* f = fopen("in.txt", "r");

	if (f == NULL)
	{
		printf("eroare legata de fisier");
		exit(1);
	}

	char c[50];
	while (fgets(c, 50, f))
	{
		int x = 0;
		for (int j = 0; j < strlen(c); j++)
		{
			if (c[j] >= '0' && c[j] <= '9')
				x = x * 10 + (c[j] - '0');
		}
		sum =sum+x;
	}

	printf("%d", sum);
	fclose(f);
	return 0;
}