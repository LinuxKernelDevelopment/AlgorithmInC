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

static int STACKremoveold(Item item)
{
	link t, p;
	if (head->item == item) {
		t = head;
		head = head->next;
		free(t);
		return 1;
	}

	for (p = head, t = p->next; t; t = t->next, p = p->next) {
		if (t->item == item) {
			p->next = t->next;
			free(t);
			return 1;
		}
	}
	return 0;
}

void STACKinit(int maxN)
{
	head == NULL;
}

void STACKpush(Item item)
{
	STACKremoveold(item);
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
