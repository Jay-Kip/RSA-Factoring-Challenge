#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int isPrime(int n)
{
	if (n <= 1)
		return (0);

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return (1);
}

void factorize(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (isPrime(i) && isPrime(n/i))
		{
			printf("%d=%d*%d\n", n, i, n / i);
			return;
		}
	}
}


void timeout_handler(int signum)
{
	printf("Execution time elapsed.\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	FILE *file;
	char *filename = argv[1];
	signal(SIGALRM, timeout_handler);

	if (argc != 2)
	{
		printf("File path not provided.\n");
		exit(1);
	}

	file = fopen(filename, "r");

	int num;

	while (fscanf(file, "%d", &num) == 1)
	{
		factorize(num);
	}


	alarm(5);


	return (0);
}
