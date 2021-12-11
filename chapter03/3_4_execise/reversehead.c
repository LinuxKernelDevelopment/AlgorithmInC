#include <stdio.h>
#include "list.h"

link reverse(link x)
{
	link t, y = x->next, r = NULL;
	while (y != NULL)
	{ t = y->next; y->next = r; r = y; y = t; }
	x->next = r->next; r->next = x;
	return r;
}

int main(int argc, char *argv[])
{
	link head = initDummyList();
	for (int i = 0; i < 100; i++) {
		link t = newNode(i);
		insertNode(head, t);
	}
	dumpList(head);
	link rev = reverse(head);
	dumpList(rev);
	return 0;
}
