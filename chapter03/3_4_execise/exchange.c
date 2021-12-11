#include <stdio.h>
#include "list.h"
#include "random.h"


int main(int argc, char *argv[])
{
	unsigned int i;
	link head = initDummyList();
	for (int i = 0; i < 100; i++) {
		link t = newNode(100 - i);
		insertNode(head, t);
	}
	link t = head;
	link u = head;
	for (i = 0; i < getUint32() % 100; i++) {
		t = t->next;
	}
	printf("i:%d\n", i);
	for (i = 0; i < getUint32() % 100; i++) {
		u = u->next;
	}
	printf("i:%d\n", i);

	dumpList(head);
	exchange(t, u);
	dumpList(head);
	return 0;
}
