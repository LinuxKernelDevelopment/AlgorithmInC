#include <stdio.h>
#include "list.h"
#include "random.h"

link copyNode(link head, int (*func)(link))
{
	link newList = initDummyList();
	link insertPos = newList;
	for (link t = head; t != NULL;) {
		link checkNode;
		if (t->next)
			checkNode = t->next;
		else
			break;
		if (func(checkNode)) {
			link tmp = deleteNext(t);
			insertNode(insertPos, tmp);
			tmp = tmp->next;
		} else
			t = t->next;
	}
	return newList;
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
	link nl = copyNode(head, odd);
	dumpList(head);
	dumpList(nl);
	return 0;
}
