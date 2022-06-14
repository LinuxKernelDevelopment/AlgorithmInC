#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

typedef struct QUEUEnode* link;
struct QUEUEnode { Item item; link next; link prev;};
static link head, tail;

link NEW(Item item, link next, link prev)
{
	link x = malloc(sizeof *x);
	x->item = item; x->next = next;
	x->prev = prev; next->prev = x;
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

void QUEUEput(Item item)
{
	if (head == NULL) {
		//head = (tail = NEW(item, head, ));
		//head->next = head;
		//head->prev = head;
		tail = head = malloc(sizeof *head);
		head->item = item;
		head->next = head;
		head->prev = head;
		return;
	}
	tail->next = NEW(item, tail->next, tail);
	tail = tail->next;
}

Item QUEUEget()
{
	Item item = head->item;
	link t = head->next;
	free(head);
	head = t;
	t->prev = tail;
	tail->next = t;
	return item;
}
