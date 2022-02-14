#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "random.h"

static Item *q;
static int N, head, tail;

void randomizedQueueInit(int maxN)
{
	q = malloc((maxN + 1) * sizeof(Item));
	N = maxN + 1;
	head = 0;
	tail = 0;
}

int randomizedQueueEmpty()
{
	return head == tail;
}

void randomizedQueuePut(Item item)
{
	int i;
	if (head == tail + 1) {
		fprintf(stderr, "Queue is full\n");
		exit(-1);
	}

	for (i = head; i != tail; i = (i + 1) % N) {
		if (q[i] == item)
			return;
	}
	q[i] = item;
	tail = (tail + 1) % N;
}

Item randomizedQueueGet()
{
	Item item;
	int j, idx;
	u_int32_t uint32rand;

	if (head == tail) {
		fprintf(stderr, "Queue is empty\n");
		exit(-1);
	}
	if (head < tail) {
		uint32rand = getUint32();
		idx = uint32rand % (tail - head) + head;
		item = q[idx];
		for (j = idx - 1; j >= head; j--) {
			q[j + 1] = q[j];
		}
	} else {
		uint32rand = getUint32();
		idx = (uint32rand % (tail + N - head) + head) % N;
		item = q[idx];
		if (idx > head) {
			for (j = idx - 1; j >= head; j--) {
				q[j + 1] = q[j];
			}
		} else {
			for (j = idx - 1; j >= 0; j--) {
				q[j + 1] = q[j];
			}
			q[N - 1] = q[0];
			for (j = N - 1; j >= head; j--) {
				q[j + 1] = q[j];
			}
		}
	}
	head = (head + 1) % N;
	return item;
}
