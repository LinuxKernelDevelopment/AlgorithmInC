#include <stdlib.h>
#include "Item.h"

typedef struct QUEUEnode* link;
struct QUEUEnode {
	link prev;
	Item item;
	link next;
};
static link head, tail;

static link NEW(Item item, link prev)
{
	link x = malloc(sizeof *x);
	x->item = item;
	prev->next->prev = x;
	x->next = prev->next;
	prev->next = x;
	x->prev = prev;
	return x;
}

void QUEUEinit(int maxN)
{
	head = malloc(sizeof *head);
	head->next = head;
	head->prev = head;
	tail = head;
}

int QUEUEempty()
{
	return head->next == head;
}

static int isDuplicate(Item item)
{
	link tmp;
	for (tmp = head->next; tmp != head; tmp = tmp->next) {
		if (tmp->item == item)
			return 1;
	}
	return 0;
}

void QUEUEput(Item item)
{
	link tmp;
	if (isDuplicate(item))
		return;
	tmp = NEW(item, head);
	tail = tail->next;
}

static link removeNext(link t)
{
	link tmp = t->next;
	if (t->next == head)
		return NULL;
	t->next->next->prev = t;
	t->next = tmp->next;
	return tmp;
}

static link removePrev(link t)
{
	link tmp = t->prev;
	if (tmp == head)
		return NULL;
	t->prev = tmp->prev;
	tmp->prev->next = t;
	return tmp;
}
	
Item QUEUEget()
{
	link tmp;
	tmp = removePrev(head);
	return tmp->item;
}
