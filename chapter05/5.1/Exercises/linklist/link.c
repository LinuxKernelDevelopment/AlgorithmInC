#include <stdlib.h>
#include <stdio.h>
#include "item.h"

typedef struct node *link;
struct node { int item; link next; };

int count(link x)
{
	if (x == NULL)
		return 0;
	return 1 + count(x->next);
}

void traverse(link h, void (*visit)(link))
{
	if (h == NULL)
		return;
	(*visit)(h);
	traverse(h->next, visit);
}

void traverseR(link h, void (*visit)(link))
{
	if (h == NULL)
		return;
	traverseR(h->next, visit);
	(*visit)(h);
}

link delete(link x, Item v)
{
	if (x == NULL)
		return NULL;
	if (x->item == v)
	{
		link t = x->next;
		free(x);
		return t;
	}
	x->next = delete(x->next, v);
	return x;
}

void deleteLast(link x)
{
	if (x->next && !x->next->next) {
		x->next = NULL;
		return;
	}

	deleteLast(x->next);
}

void visit(link x)
{
	printf("%d\t", x->item);
}
