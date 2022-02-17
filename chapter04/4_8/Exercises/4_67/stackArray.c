#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

struct stack {
	Item *s;
	int num;
	int maxN;
};
typedef struct stack *STACK;
STACK STACKinit(int maxN)
{
	STACK x = malloc(sizeof *x);
	x->s = malloc(maxN * sizeof(Item));
	x->num = 0;
	x->maxN = maxN;
	return x;
}

int STACKempty(STACK s)
{
	return s->num == 0;
}

void STACKpush(STACK s, Item item)
{
	s->s[s->num++] = item;
}

Item STACKpop(STACK s)
{
	return s->s[--s->num];
}
