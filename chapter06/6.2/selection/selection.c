#include <stdio.h>
#include <stdlib.h>

typedef	int Item;
#define	key(A)	(A)
#define	less(A, B)	(key(A) < key(B))
#define	exch(A, B)	{ Item t = A; A = B; B = t; }
#define	compexch(A, B)	if (less(B, A)) exch(A, B)

void selection(Item a[], int l, int r)
{
	int i, j;
	for (i = l; i < r; i++)
	{
		int min = i;
		for (j = i + 1; j <= r; j++)
			if (less(a[j], a[min])) min = j;
		exch(a[i], a[min]);
	}
}

int main(int argc, char *argv[])
{
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int *a = malloc(N * sizeof(int));
	if (sw)
		for (i = 0; i < N; i++)
			a[i] = 1000 * (1.0 * rand() / RAND_MAX);
	else
		while (scanf("%d", &a[N]) == 1) N++;
	selection(a, 0, 999);
	for (i = 0; i < N; i++) printf("%3d ", a[i]);
	printf("\n");
}
