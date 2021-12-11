#include <stdlib.h>
#include <stdio.h>
#include "doubleList.h"

doubleLink newNode(int itemValue)
{
	doubleLink t = malloc(sizeof *t);
	t->item = itemValue;
	t->prev = NULL;
	t->next = NULL;
	return t;
}

void freeNode(doubleLink t)
{
	free(t);
}

void insertNode(doubleLink x, doubleLink t)
{
	t->next = x->next;
	t->prev = x;
	if (x->next) {
		x->next->prev = t;
	}
	x->next = t;
}

doubleLink initDummyList()
{
	doubleLink head = malloc(sizeof *head);
	if (head == NULL) {
		perror("malloc failed");
		exit(-1);
	}
	head->next = NULL;
	head->prev = NULL;
	return head;
}

void dumpList(doubleLink t)
{
	t = t->next;
	while (t) {
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");
}

void exchangeDouble(doubleLink a, doubleLink b)
{
	doubleLink ap, an, bp, bn;
	ap = a->prev;
	an = a->next;
	bp = b->prev;
	bn = b->next;
	ap->next = b;
	if (an)
		an->prev = b;
	bp->next = a;
	if (bn)
		bn->prev = a;
	b->prev = ap;
	b->next = an;
	a->prev = bp;
	a->next = bn;
}
