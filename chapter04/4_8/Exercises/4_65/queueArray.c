#include <stdlib.h>
#include "Item.h"

typedef struct queue {
	int head;
	int tail;
	Item *q;
	int N;
} QUEUE;

QUEUE *QUEUEinit(int maxN)
{
	QUEUE *q = malloc(sizeof(QUEUE));
	q->head = 0;
	q->tail = 0;
	q->q = malloc(sizeof(Item) * maxN);
	q->N = maxN;
	return q;
}

int QUEUEempty(QUEUE *q)
{
	return q->head == q->tail;
}

void QUEUEput(QUEUE *q, Item item)
{
	q->q[q->tail] = item;
	q->tail = (q->tail + 1) % q->N;
}

Item QUEUEget(QUEUE *q)
{
	Item item = q->q[q->head];
	q->head = (q->head + 1) % q->N;
	return item;
}
