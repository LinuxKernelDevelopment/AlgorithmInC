#include <stdio.h>
#include <stdlib.h>

int *pnr;

int pneval(int n)
{
	int t;

	if (pnr[n] != -1)
		return pnr[n];

	if (n == 0)
		return 0;
	
	if (n == 1)
		return 1;

	if (!(n % 2))
		t = n / 2 + pneval(n / 2) + pneval(n / 2);
	else
		t = n / 2 + pneval(n / 2) + pneval(n / 2 + 1);

	return pnr[n] = t;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	pnr = malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++)
		pnr[i] = -1;

	printf("%d\n", pneval(n));

	return 0;
}
