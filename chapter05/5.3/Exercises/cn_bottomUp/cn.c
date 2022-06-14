#include <stdio.h>
#include <stdlib.h>

int *cn;

int computeCn(int n)
{
	int sum = 0;

	if (n == 0)
		return 1;

	if (cn[n] != -1)
		return cn[n];

	for (int k = 1; k < n + 1; k++)
	{
		sum += computeCn(k - 1) + computeCn(n - k);
	}

	return cn[n] = (n + sum / n);
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	cn = malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++)
		cn[i] = -1;


	printf("%d\n", computeCn(n));
	return 0;
}
