#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
typedef struct STACKnode* link;
struct STACKnode { Item item; link next; };
static link head;
static int N = 0;
link NEW(Item item, link next)
{
	link x = malloc(sizeof *x);
	x->item = item; x->next = next;
	return x;
}

void STACKerror()
{
	fprintf(stderr, "stack exception");
	exit(-1);
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
	if (count() == 0) {
		STACKerror();
	}

	Item item = head->item;
	link t = head->next;
	free(head); head = t;
	N -= 1;
	return item;
}
