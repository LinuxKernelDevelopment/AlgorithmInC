#include <stdio.h>
#include <stdlib.h>
#include "doubleList.h"
#include "random.h"

int main(int argc, char *argv[])
{
	int num = atoi(argv[1]);
	doubleLink head = initDummyList();
	doubleLink ins = head;
	int i;
	for (i = 0; i < num; i++) {
		doubleLink tmp = newNode(i);
		insertNode(ins, tmp);
		ins = ins->next;
	}
	doubleLink p10, p20;
	for (p10 = head->next, i = 0; i < 0; i++)
		p10 = p10->next;
	for (p20 = head->next, i = 0; i < 100 && p20->next; i++)
		p20 = p20->next;
	
	dumpList(head);
	exchangeDouble(p10, p20);
	dumpList(head);
	return 0;
}
