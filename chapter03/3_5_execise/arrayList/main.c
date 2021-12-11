#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "random.h"

elem elemInsertionSort(elem head)
{
	elem headb = NULL;
	elem b = headb;
	elem a = head;
	elem t, u, pt;
	elem x, tmp;
	for (t = a; t->next != ELEM_END; t = u) {
		u = Next(t);
		for (x = b; x && x->next != ELEM_END; x = Next(x))
			if (Next(x)->item > t->item) break;
		tmp = a;
		tmp->next = ELEM_END;
		a = u;
		if (b == NULL)
			b = tmp;
		else if (Item(tmp) > Item(x))
			insertNext(x, tmp);
		else {
			insertNext(tmp, x);
			b = tmp;
			x->next = ELEM_END;
		}
	}
	return b;
}

int main(int argc, char *argv[])
{
	elem t;
	initNodes(100);
	elem head = newNode(getInt32());
	elem ins = head;
	for (int i = 1; i < 100; i++) {
		t = newNode(getInt32());
		insertNext(ins, t);
		ins = Next(ins);
	}
	dumpNodes(head);
	printf("\n");
	head = elemInsertionSort(head);
	dumpNodes(head);
	return 0;
}
