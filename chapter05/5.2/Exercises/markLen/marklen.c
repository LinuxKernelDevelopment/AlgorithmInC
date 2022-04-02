#include <stdio.h>

int marklen(int l, int r, int i, int h)
{
	int m = (l + r) / 2;

	if (m == i)
		return h;

	if (i < m)
		return marklen(l, m, i, h - 1);
	else
		return marklen(m, r, i, h - 1);
}

int main(int argc, char *argv[])
{
	printf("%d\n", marklen(0, 16, 4, 4));
	return 0;
}
