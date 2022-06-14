#include <stdio.h>
#include <stdlib.h>

int computeCn(int n)
{
	int sum = 0;

	if (n == 0)
		return 1;

	for (int k = 1; k < n + 1; k++)
	{
		sum += computeCn(k - 1) + computeCn(n - k);
	}

	return n + sum / n;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	printf("%d\n", computeCn(n));
	return 0;
}
