#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static int N;
static int topIndex;
static int maxNum;

typedef struct {
	Item item;
	int prev;
} arrayIndiceStackEntry;

static arrayIndiceStackEntry *s;

void STACKinit(int maxN)
{
	s = malloc(sizeof(arrayIndiceStackEntry) * maxN);
	for (int i = 0; i < maxN; i++)
		s[i].prev = -1;
	maxNum = maxN;
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
	int i = 0;
	for (i = 0; i < maxNum; i++) {
		if (s[i].prev == -1)
			break;
	}
	s[i].item = item;
	s[i].prev = topIndex;
	topIndex = i;
	N += 1;
}

Item STACKpop()
{
	Item ret = s[topIndex].item;
	arrayIndiceStackEntry tmp = s[topIndex];
	topIndex = tmp.prev;
	tmp.prev = -1;
	N -= 1;
	return ret;
}
