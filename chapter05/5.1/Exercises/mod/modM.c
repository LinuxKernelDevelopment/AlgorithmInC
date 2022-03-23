#include <stdio.h>
#include <stdlib.h>

int modM(int n, int m)
{
	int val;

	if (n == 1)
		return 1;
	val = modM(n - 1, m);
	val = n * val;
	if (val > m)
		val = val % m;
	return val;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int p = atoi(argv[2]);
	printf("%d\n", modM(n, p));
	return 0;
}
