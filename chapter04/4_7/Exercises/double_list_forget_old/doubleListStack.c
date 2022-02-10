#include <stdlib.h>
#include "Item.h"

typedef struct STACKnode* link;
struct STACKnode {
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

void STACKinit(int maxN)
{
	int i;
	head = malloc(sizeof *head);
	head->next = NULL;
	head->prev = NULL;

	t = malloc(maxN * sizeof(link));
	for (i = 0; i < maxN; i++) t[i] = NULL;
}

static link removeCurr(link tmp)
{
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	return tmp;
}

void STACKpush(Item item)
{
	link tmp;
	if (t[item]) {
		tmp = removeCurr(t[item]);
		free(tmp);
	}
	tmp = NEW(item, head);
	t[item] = tmp;
}

static link removeNext(link t)
{
	link tmp;
	if (!t->next)
		return NULL;
	tmp = t->next;
	removeCurr(tmp);
	return tmp;
}

Item STACKpop()
{
	link tmp;
	tmp = removeNext(head);
	t[tmp->item] = NULL;
	return tmp->item;
}

