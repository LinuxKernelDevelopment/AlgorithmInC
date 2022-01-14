#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "STACK.h"
static Item *s;
static int N;
static int maxItem;
void STACKinit(int maxN)
{
	s = malloc(maxN * sizeof(Item));
	N = 0;
	maxItem = maxN;
}

void STACKerror()
{
	fprintf(stderr, "stack error\n");
	exit(-1);
}

int count()
{
	return N;
}

int STACKempty()
{
	return count() == 0;
}

void STACKpush(Item item)
{
	if (count() >= maxItem)
	       STACKerror();
	s[N++] = item; 
}

Item STACKpop()
{
	if (count() == 0)
		STACKerror();
	return s[--N];
}
