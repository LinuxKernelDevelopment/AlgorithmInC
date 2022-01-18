#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

static Item *q;
static int N, head, tail;

void QUEUEerror()
{
	if (tail + 1 == head) {
		fprintf(stderr, "Queue is full.\n");
		exit(-1);
	}
	else {
		fprintf(stderr, "Queue is empty.\n");
		exit(-1);
	}
}

void QUEUEinit(int maxN)
{
	q = malloc((maxN+1) * sizeof(Item));
	N = maxN + 1;
	head = N;
	tail = 0;
}

int QUEUEempty()
{
	return head % N == tail;
}

void QUEUEput(Item item)
{
	if (tail + 1 == head)
		QUEUEerror();
	q[tail++] = item;
	tail = tail % N;
}

Item QUEUEget()
{
	head = head % N;
	if (head == tail)
		QUEUEerror();
	return q[head++];
}
