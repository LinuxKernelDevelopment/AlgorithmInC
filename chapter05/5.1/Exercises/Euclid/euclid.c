#include <stdio.h>
#include <stdlib.h>

int euclid(int m, int n)
{
	int t;

	while (n) {
		t = m % n;
		m = n;
		n = t;
	}
	return m;
}

int main(int argc, char *argv[])
{
	int p = atoi(argv[1]);
	int q = atoi(argv[2]);
	printf("%d\n", euclid(p, q));
	return 0;
}
