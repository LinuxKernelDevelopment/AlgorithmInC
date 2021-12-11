#include <stdio.h>
#include "list.h"
#include "random.h"

int removeNode(link head, int (*func)(link))
{
	for (link t = head; t != NULL;) {
		link checkNode;
		if (t->next)
			checkNode = t->next;
		else
			break;
		if (func(checkNode))
			deleteNext(t);
		else
			t = t->next;
	}
	return 0;
}

int odd(link t) {
	return t->item % 2;
}

int main(int argc, char *argv[])
{
	link head = initDummyList();
	for (int i = 0; i < 100; i++) {
		link t = newNode(getInt32());
		insertNode(head, t);
	}
	dumpList(head);
	removeNode(head, odd);
	dumpList(head);
	return 0;
}
