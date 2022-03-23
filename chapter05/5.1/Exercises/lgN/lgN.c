#include <stdio.h>
#include <math.h>

int factorial(int n)
{
	if (n == 1)
		return 1;

	return n * factorial(n - 1);
}

double log2n(int n)
{
	int val;

	val = factorial(n);

	return log2(val);
}

int main()
{
	printf("%f\n", log2n(2));
	return 0;
}
