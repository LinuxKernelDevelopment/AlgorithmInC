#include <stdio.h>
#include <stdlib.h>

typedef	int Item;
#define	key(A)	(A)
#define	less(A, B)	(key(A) < key(B))
#define	exch(A, B)	{ Item t = A; A = B; B = t; }
#define	compexch(A, B)	if (less(B, A)) exch(A, B)

void bubble(Item a[], int l, int r)
{
	int i, j;
	int t;
	int k;
	for (i = l; i < r; i++) {
		for (j = r, t = r; j >= i; j--) {
			if (a[j] < a[t])
				t = j;
		}
		int tmp = a[i]; a[i] = a[t]; a[t] = tmp;
	}
}

int main(int argc, char *argv[])
{
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int *a = malloc(N * sizeof(int));
	if (sw)
		for (i = 0; i < N; i++)
			a[i] = N * (1.0 * rand() / RAND_MAX);
	else
		while (scanf("%d", &a[N]) == 1) N++;
	bubble(a, 0, N - 1);
	for (i = 0; i < N; i++) printf("%3d ", a[i]);
	printf("\n");
}
