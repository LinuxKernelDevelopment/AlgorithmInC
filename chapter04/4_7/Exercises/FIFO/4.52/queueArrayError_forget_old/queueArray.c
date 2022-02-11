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
	head = N - 1;
	tail = 0;
}

int QUEUEempty()
{
	return head % N == tail;
}

void QUEUEput(Item item)
{
	int i, j;
	for (i = (head + 1) % N; i % N != tail; i++) {
		if (q[i] == item)
			break;
	}

	if (i % N != tail) {
		for (j = i; j % N != tail; j++) {
			q[j % N] = q[(j+1) % N];
		}
		if (tail == 0)
			tail = N - 1;
		else
			tail -= 1;
	}

	if (tail % N == head)
		QUEUEerror();
	q[tail] = item;
	tail = (tail + 1) % N;
}

Item QUEUEget()
{
	Item item;
	if (head % N == tail)
		QUEUEerror();
	head = (head + 1) % N;
	item = q[head];
	return item;
}
