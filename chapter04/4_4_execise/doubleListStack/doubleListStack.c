#include <stdlib.h>
#include "Item.h"

typedef struct STACKnode* link;
struct STACKnode { Item item; link prev; link next; };
static link head;
static int N = 0;

link NEW(Item item, link next)
{
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	if (next)
		next->prev = x;
	return x;
}

void STACKinit(int maxN)
{
	head = NULL;
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
	head = NEW(item, head);
	N += 1;
}

Item STACKpop()
{
	Item item = head->item;
	link t = head->next;
	free(head); head = t;
	if(head)
		head->prev = NULL;
	N -= 1;
	return item;
}
