#include <stdio.h>
#include "list.h"
#include "random.h"

link moveEven(link head)
{
	link t = head->next;
	link firstEvenPos;
	link tail;

	while (t) {
		tail = t;
		t = t->next;
	}
	t = head->next;
	if (t->next) {
		firstEvenPos = deleteNext(t);
		insertNode(tail, firstEvenPos);
		tail = tail->next;
	}

	for (int i = 1; t != firstEvenPos; t = t->next, i++) {
		if (i % 2 == 0) {
			link tmp = deleteNext(t);
			insertNode(tail, tmp);
			tail = tail->next;
			i++;
		}
	}
}

int main(int argc, char *argv[])
{
	link head = initDummyList();
	for (int i = 0; i < 100; i++) {
		link t = newNode(100 - i);
		insertNode(head, t);
	}
	dumpList(head);
	moveEven(head);
	dumpList(head);
	return 0;
}
