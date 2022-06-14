#include <stdio.h>
#include <stdlib.h>

typedef struct { int size; int val; } Item;

Item *items;
int N;
int max = 0;

int knap(int cap)
{
	int i, space, max, t;
	for (i = 0, max = 0; i < N; i++)
		if ((space = cap - items[i].size) >= 0)
			if ((t = knap(space) + items[i].val) > max)
				max = t;
	return max;
}

int main()
{
	N = 5;
	items = malloc(sizeof(Item) * N);
	items[0].size = 3;
	items[0].val = 4;

	items[1].size = 4;
	items[1].val = 5;

	items[2].size = 7;
	items[2].val = 10;

	items[3].size = 8;
	items[3].val = 11;

	items[4].size = 9;
	items[4].val = 13;

	printf("max:%d\n", knap(17));
	return 0;
}
