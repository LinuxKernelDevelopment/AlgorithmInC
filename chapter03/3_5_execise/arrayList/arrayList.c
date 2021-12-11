#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

struct globalTable gt;

void initNodes(int num)
{
	gt.nodeTable = malloc(sizeof(struct node) * num);
	if (!gt.nodeTable) {
		fprintf(stderr, "malloc failed");
		exit(-1);
	}
	for (int i = 0; i < num; i++)
		gt.nodeTable[i].next = ELEM_DNE;
	gt.num = num;
}

elem newNode(int item)
{
	elem t;
	int index;
	for (index = 0; index < gt.num; index++) {
		if (gt.nodeTable[index].next == ELEM_DNE)
			break;
	}
	t = &gt.nodeTable[index];
	t->item = item;
	t->next = ELEM_END;
	return t;
}

void freeNode(elem t)
{
	t->next = -1;
}

void insertNext(elem x, elem t)
{
	t->next = x->next;
	x->next = t - gt.nodeTable;
}

elem deleteNext(elem x)
{
	if (x->next == -1) {
		fprintf(stderr, "the element is free\n");
		exit(-1);
	}
	elem t = &gt.nodeTable[x->next];
	x->next = t->next;
	t->next = ELEM_DNE;
	return t;
}

elem Next(elem x)
{
	return &gt.nodeTable[x->next];
}

int Item(elem t)
{
	return t->item;
}

void dumpTable()
{
	for (int i = 0; i < gt.num; i++) {
		printf("item:%d, next:%d\n", gt.nodeTable[i].item, gt.nodeTable[i].next);
	}
}

void dumpNodes(elem t)
{
	do {
		printf("%d ", t->item);
		t = &gt.nodeTable[t->next];
	} while (t->next != ELEM_END);
	printf("%d ", t->item);
}
