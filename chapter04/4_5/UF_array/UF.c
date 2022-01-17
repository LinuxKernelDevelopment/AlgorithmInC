#include <stdlib.h>
#include "UF.h"
static int *pat;
void UFinit(int N)
{
	int i;
	pat = malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
	{ pat[i] = i; }
}

static int find(int x)
{
	int i = x;
	while (i != pat[i]) i = pat[i];
	return i;
}

int UFfind(int p, int q)
{
	return (find(p) == find(q));
}

void UFunion(int p, int q)
{
	int i = find(p), j = find(q);
	if (i == j)
		return;
	pat[i] = j;
}
