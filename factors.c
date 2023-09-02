#include <stdio.h>
#include <stdlib.h>

void factorize(int n)
{
	char line[256];
	int i;

	for (i = 2; i * i <= n; i++)
	{
		printf("%d=%d*%d\n", n, i, n / i);
	}

}


int main(int argc, char *argv[])
{
	FILE *file;
	char *filename = argv[1];

	file = fopen(filename, "r");

	int number;

	while (fscanf(file, "%d", &number) == 1)
	{
		factorize(number);
	}

	/*if (file == NULL)
	{
		printf("Failed to open file: %s\n", filename);
		return (1);
	}*/

	//factorize(file);


	fclose(file);

	return (0);
}

