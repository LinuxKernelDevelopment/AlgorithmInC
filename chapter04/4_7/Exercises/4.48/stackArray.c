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
	int i;
	for (i = 0; i < N; i++) {
		if (s[i] == item)
			return;
	}
	s[N++] = item;
}

Item STACKpop()
{
	return s[--N];
}
