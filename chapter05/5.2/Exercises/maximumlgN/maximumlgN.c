#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Item int

static int computeN(int l, int r)
{
	int size = r - l;
	int i, n = 1;

	for (i = 0; (n << i) < r - l + 1; i ++);

	return n << (i - 1);
}

Item maxlgN(Item a[], int l, int r)
{
	int n;
	Item u, v;
	n = computeN(l, r);
	if (l == r) return a[l];
	u = maxlgN(a, l, l + n - 1);
	v = maxlgN(a, l + n, r);
	if (u > v) return u; else return v;
}

int main(int argc, char *argv[])
{
	int a[] = {378, 732, 34, 4897, 4786, 48793, 47, 487, 47, 45, 489, 7832 };

	int m = maxlgN(a, 0, sizeof(a) / sizeof(int) - 1);

	printf("%d\n", m);

	return 0;
}
