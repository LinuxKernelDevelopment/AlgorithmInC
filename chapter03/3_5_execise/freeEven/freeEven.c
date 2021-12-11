#include <stdio.h>
#include "list.h"

int freeEven(link head)
{
	link t = head;
	for (int i = 1; i < 100; i++) {
		if (!(i % 2)) {
			link tmp = deleteNext(t);
			freeNode(tmp);
		} else {
			t = t->next;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	link head = initDummyList();
	link t = head;
	for (int i = 1; i < 100; i++) {
		link tmp = newNode(i);
		insertNode(t, tmp);
		t = t->next;
	}
	dumpList(head);
	freeEven(head);
	dumpList(head);
	return 0;
}
