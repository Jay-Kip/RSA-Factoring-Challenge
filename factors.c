#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void factorize(int n)
{
	char line[256];
	int div = 2;

	while (n > 1)
	{
		if (n % div == 0)
		{
			printf("%d=%d*%d\n", n, div, n / div);
			n /= div;
		}
		else
		{
			div++;
		}
	}

}
void timeout_handler(int signum)
{
	printf("Program timed out.\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	FILE *file;
	char *filename = argv[1];
	signal(SIGALRM, timeout_handler);

	if (argc != 2)
	{
		printf("File path not provided\n");
		return (1);
	}
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
	alarm(5);

	fclose(file);

	return (0);
}

