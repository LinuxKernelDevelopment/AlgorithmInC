#include <stdio.h>
#include "list.h"
#include "random.h"

link listInsertionSort(link head)
{
	link b = initNoDummyList();
	link u, x;
	link prev = b;
	if (!head)
		return NULL;
	for (link t = head; t!= NULL; t = u) {
		u = t->next;
		link ins = t;
		ins->next = NULL;
		for (x = b; x != NULL; x = x->next) {
			if (x == NULL) {
				b = ins;
				break;
			}
			if (x->next == NULL)
				break;
			if (x->next->item > t->item)
				break;
		}
		if (!x) {
			b = ins;
		} else {
			if (x == b && x->item > ins->item) {
				ins->next = b->next;
				b = ins;
			} else {
				ins->next = x->next;
				x->next = ins;
			}
		}
	}
	return b;
}

int main(int argc, char *argv[])
{
	int i;
	link t;
	link head = initNoDummyList();
	for (i = 0, t = head; i < 100; i++) {
		t = newNode(getInt32());
		insertNoDummyNode(&head, t);
	}
	dumpNoDummyList(head);
	link sl = listInsertionSort(head);
	dumpNoDummyList(sl);
	freeList(sl);
	return 0;
}
