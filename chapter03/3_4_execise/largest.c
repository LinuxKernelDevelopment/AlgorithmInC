#include <stdio.h>
#include "list.h"
#include "random.h"

link moveLargest(link head)
{
	link t = head->next;
	link max = t;
	link maxPrev = head;
	link prev = head;
	while (t) {
		if (t->item > max->item) {
			max = t;
			maxPrev = prev;
		}
		prev = prev->next;
		t = t->next;
	}
	link del = deleteNext(maxPrev);
	insertNode(prev, del);
	return head;
}

int main(int argc, char *argv[])
{
	link head = initDummyList();
	for (int i = 0; i < 10; i++) {
		link t = newNode(getInt32());
		insertNode(head, t);
	}
	dumpList(head);
	moveLargest(head);
	dumpList(head);
	return 0;
}
