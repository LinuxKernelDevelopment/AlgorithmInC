#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

static Item *q;
static int N, head, tail;
static int *t;

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
	t = malloc(maxN * sizeof(int));
}

int QUEUEempty()
{
	return head % N == tail;
}

void QUEUEput(Item item)
{
	if (t[item] == 1)
		return;
	if (tail % N == head)
		QUEUEerror();
	q[tail] = item;
	tail = (tail + 1) % N;
	t[item] = 1;
}

Item QUEUEget()
{
	Item item;
	if (head % N == tail)
		QUEUEerror();
	head = (head + 1) % N;
	item = q[head];
	t[item] = 0;
	return item;
}
