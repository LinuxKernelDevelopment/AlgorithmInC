#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "link.h"

int main(void)
{
	int i;
	link t = malloc(sizeof *t), x = t;
	t->item = 1; t->next = NULL;
	for (i = 2; i <= 10; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i; x->next = NULL;
	}
	traverse(t, visit);
	printf("\n");
	deleteLast(t);
	traverse(t, visit);
	printf("\n");
	return 0;
}
