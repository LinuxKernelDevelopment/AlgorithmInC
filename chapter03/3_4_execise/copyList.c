#include <stdio.h>
#include "list.h"
#include "random.h"

link copyList(link head)
{
	link newList = initDummyList();
	link insertPos = newList;
	for (link t = head->next; t != NULL; t = t->next) {
		link new = newNode(t->item);
		insertNode(insertPos, new);
		insertPos = insertPos->next;
	}
	return newList;
}

int main(int argc, char *argv[])
{
	link head = initDummyList();
	for (int i = 0; i < 10; i++) {
		link t = newNode(getInt32());
		insertNode(head, t);
	}
	dumpList(head);
	link copy = copyList(head);
	dumpList(copy);
	return 0;
}
