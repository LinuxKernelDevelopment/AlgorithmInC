#include <stdlib.h>
#include "Item.h"

typedef struct QUEUEnode* link;
struct QUEUEnode {
	link prev;
	Item item;
	link next;
};
static link head;
static link *t;

static link NEW(Item item, link prev)
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

void QUEUEinit(int maxN)
{
	int i;
	head = malloc(sizeof *head);
	head->next = head; 
	head->prev = head;

	t = malloc(maxN * sizeof(link));
	for (i = 0; i < maxN; i++) t[i] = NULL;
}

int QUEUEempty()
{
	return head->next == head;
}

static link removeCurr(link tmp)
{
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	return tmp;
}

void QUEUEput(Item item)
{
	link tmp;
	if (t[item]) {
		tmp = removeCurr(t[item]);
		free(tmp);
	}
	tmp = NEW(item, head);
	t[item] = tmp;
}

static link removePrev(link t)
{
	link tmp;
	if (t->prev == head)
		return NULL;
	tmp = t->prev;
	removeCurr(tmp);
	return tmp;
}

Item QUEUEget()
{
	link tmp;
	tmp = removePrev(head);
	t[tmp->item] = NULL;
	return tmp->item;
}
