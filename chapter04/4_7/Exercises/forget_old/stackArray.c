#include <stdlib.h>
#include "Item.h"
#include "STACK.h"
static Item *s;
static int N;

void STACKinit(int maxN)
{
	s = malloc(maxN * sizeof(Item));
	N = 0;
}

int STACKempty()
{
	return N == 0;
}

void STACKpush(Item item)
{
	int i, j;
	for (i = 0; i < N; i++) {
		if (s[i] == item)
			break;
	}
	if (i != N) {
		for (j = i; j < N - 1; j++) {
			s[j] = s[j+1];
		}
		N -= 1;
	}
	s[N++] = item;
}

Item STACKpop()
{
	return s[--N];
}
