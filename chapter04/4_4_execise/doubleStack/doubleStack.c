#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "doubleStack.h"
static Item *s;
static int headIdx;
static int tailIdx;
static int maxNum;

void STACKinit(int maxN)
{
	s = malloc(maxN * sizeof(Item));
	headIdx = 0;
	tailIdx = maxN - 1;
	maxNum = maxN;
}

int headCount()
{
	return headIdx;
}

int tailCount()
{
	return maxNum - tailIdx - 1;
}

void headPush(Item item)
{
	assert(headIdx < tailIdx);

	s[headIdx++] = item;
}

Item headPop()
{
	return s[--headIdx];
}

void tailPush(Item item)
{
	assert(headIdx < tailIdx);

	s[tailIdx--] = item;
}

Item tailPop()
{
	return s[--tailIdx];
}
	
