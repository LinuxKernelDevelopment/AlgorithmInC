#include <stdlib.h>
#include <assert.h>
#include "Item.h"

typedef struct Listnode *link;
struct Listnode { Item item; link prev; link next; };

link ListInit(void)
{
	link head = malloc(sizeof *head); // dummy head
	assert(head);
	return head;
}

link NEW(Item item, link prev)
{
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = prev->next;
	if (prev->next)
		prev->next->prev = x;
	prev->next = x;
	x->prev = prev;
	return x;
}

link DEL(link x)
{
	link prev = x->prev;
	link next = x->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	return x;
}

Item ListNextVal(link *t)
{
	Item c;
	if ((*t)->next) {
		c = (*t)->next->item;
		*t = (*t)->next;
		return c;
	} else {
		*t = NULL;
		return -1;
	}
}

void ListLinkTail(link a, link b)
{
	link p, q;

	for (p = a->next; p->next != NULL; p = p->next);

	for (q = b->next; q != NULL; q = q->next) {
		NEW(q->item, p);
		p = p->next;
	}
	p->next = NULL;
}

void ListDestroy(link t)
{
	link tmp;
	while (t) {
		tmp = t;
		t = t->next;
		free(tmp);
	}
}

int ListCmp(link a, link b)
{
	link p, q;
	for (p = a->next, q = b->next; p != NULL && q != NULL; p = p->next, q = q->next) {
		if (p->item == q->item)
			continue;
		else
			return p->item - q->item;
	}

	if (p)
		return p->item;
	else if (q)
		return -q->item;
	else
		return 0;
}

void ListFun(link a, void (*fn)(char))
{
	link t;
	for (t = a->next; t != NULL; t = t->next) {
		fn(t->item);
	}
}
