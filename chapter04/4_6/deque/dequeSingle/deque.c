#include <stdlib.h>
#include "Item.h"
#include "deque.h"

typedef struct QUEUEnode* link;
struct QUEUEnode { Item item; link next; };
static link head, tail;

link NEW(Item item, link next)
{
	link x = malloc(sizeof *x);
	x->item = item; x->next = next;
	return x;
}

void QUEUEinit(int maxN)
{
	head = NULL;
}

int QUEUEempty()
{
	return head == NULL;
}

void push_back(Item item)
{
	if (head == NULL) {
		head = (tail = NEW(item, head));
		return;
	}
	tail->next = NEW(item, tail->next);
	tail = tail->next;
}

void push_front(Item item) //new interface
{
	if (head == NULL) {
		head = (tail = NEW(item, head));
		return;
	}
	head = NEW(item, head);
}

Item pop_front()
{
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}

Item pop_back()
{
	Item item = tail->item;
	link tmp = head;
	while (tmp && tmp->next != tail) 
		tmp = tmp->next;
	free(tail);
	tail = tmp;
	return item;
}
