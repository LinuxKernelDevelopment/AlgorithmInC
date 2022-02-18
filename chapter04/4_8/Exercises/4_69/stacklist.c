#include <stdlib.h>
#include <assert.h>
#include "COMPLEX.h"
#include "Item.h"
typedef struct STACKnode* link;
struct STACKnode { Item item; link next; };

struct stack {
	link head;
	int num;
};

typedef struct stack *STACK;

link NEW(Item item, link next)
{
	link x = malloc(sizeof *x);
	x->item = item; x->next = next;
	return x;
}

STACK STACKinit(int maxN)
{
	STACK x = malloc(sizeof *x);
	x->head = NULL;
	x->num = 0;
	return x;
}

int STACKempty(STACK s)
{
	return s->head == NULL;
}

void STACKpush(STACK s, Item item)
{
	s->head = NEW(item, s->head);
	s->num += 1;
}

Item STACKpop(STACK s)
{
	assert(!STACKempty(s));
	Item item = s->head->item;
	link t = s->head->next;
	free(s->head); s->head = t;
	s->num -= 1;
	return item;
}
