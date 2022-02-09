#include <stdlib.h>
#include "Item.h"
typedef struct STACKnode* link;
struct STACKnode { Item item; link next; };
static link head;
link NEW(Item item, link next)
{
	link x = malloc(sizeof *x);
	x->item = item; x->next = next;
	return x;
}

int STACKexist(Item item)
{
	link t;
	for (t = head; t; t = t->next) {
		if (t->item == item)
			return 1;
	}
	return 0;
}

void STACKinit(int maxN)
{
	head == NULL;
}

void STACKpush(Item item)
{
	if (STACKexist(item))
		return;
	head = NEW(item, head);
}

Item STACKpop()
{
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}
