#include <stdio.h>

int maximum(int a[], int l, int h)
{
	if (l == h)
		return a[l];

	if (a[l] > maximum(a, l + 1, h))
		return a[l];
	else
		return maximum(a, l + 1, h);
}

int main(void)
{
	int a[] = { 127, 8791, 6782, 7, 37, 789};
	printf("max:%d\n", maximum(a, 0, 5));
	return 0;
}
