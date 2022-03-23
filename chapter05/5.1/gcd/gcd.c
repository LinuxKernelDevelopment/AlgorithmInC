#include <stdio.h>

int gcd(int m, int n)
{
	if (n == 0) return m;
	return gcd(n, m % n);
}

int main(int argc, char *argv[])
{
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	printf("%d %d: %d\n", num1, num2, gcd(num1, num2));
	return 0;
}
