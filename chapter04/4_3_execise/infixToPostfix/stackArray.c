#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

Stack *STACKinit(int maxN)
{ 
	Stack *st = malloc(sizeof(Stack));
	st->s = malloc(maxN * sizeof(Item));
	st->N = 0;
	return st;
}
int STACKempty(Stack *st)
{ return st->N == 0; }

void STACKpush(Stack *st, Item item)
{ st->s[st->N++] = item; }

Item STACKpop(Stack *st)
{ return st->s[--st->N]; }
