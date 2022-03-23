#include <stdio.h>

int factorial(int N)
{
	if (N == 0) return 1;
	return N * factorial(N - 1);
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	printf("%d : %d\n", n, factorial(n));
	return 0;
}
