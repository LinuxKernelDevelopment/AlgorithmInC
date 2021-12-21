#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Smax 100
#define Nmax 1000

int compare(void *i, void *j)
{ return strcmp(*(char **)i, *(char **)j); }

int main()
{
	int i, N;
	char *a[Smax];
	char *buf;
	for (N = 0; N < Nmax; N++)
	{
		buf = calloc(Smax, sizeof(char));
		a[N] = &buf[0];
		if (scanf("%s", a[N]) == EOF) break;
	}
	printf("\n");
	qsort(a, N, sizeof(char*), compare);
	for (i = 0; i < N; i++) printf("%s\n", a[i]);
	return 0;
}
