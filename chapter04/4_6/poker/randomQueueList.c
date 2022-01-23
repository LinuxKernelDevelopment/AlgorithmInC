#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "randomQueue.h"
#include "random.h"

randomQueueEntry *randomQueueHead;
int randomQueueSizeVar = 0;

void randomQueueInit(int maxN)
{
	randomQueueEntry *dummy;
	dummy = calloc(0, sizeof(randomQueueEntry));
	if (!dummy) {
		perror("calloc failed");
		exit(-1);
	}
	dummy->next = NULL;
	randomQueueHead = dummy;
}

int randomQueueSize()
{
	return randomQueueSizeVar;
}

void randomQueueEnqueue(Item item)
{
	randomQueueEntry *tmp;
	tmp = calloc(0, sizeof(randomQueueEntry));
	if (!tmp) {
		perror("calloc failed");
		exit(-1);
	}
	tmp->item = item;
	tmp->next = randomQueueHead->next;
	randomQueueHead->next = tmp;
	randomQueueSizeVar += 1;
}

Item randomQueueDequeue()
{
	unsigned int randomNum = getUint32();
	int num = randomNum % randomQueueSizeVar;
	Item ret;
	randomQueueEntry *tmp;
	randomQueueEntry *prev = randomQueueHead;
	for (tmp = randomQueueHead->next; tmp && num != 0;) {
		prev = prev->next;
		tmp = tmp->next;
		num -= 1;
	}
	prev->next = tmp->next;
	ret = tmp->item;
	free(tmp);
	randomQueueSizeVar -= 1;
	return ret;
}

Item randomQueueSample()
{
	unsigned int randomNum = getUint32();
	int num = randomNum % randomQueueSizeVar;
	randomQueueEntry *tmp;
	tmp = calloc(0, sizeof(randomQueueEntry));
	for (randomQueueEntry *tmp = randomQueueHead->next; tmp && num != 0; tmp = tmp->next) {
		num -= 1;
	}
	return tmp->item;
}

void outPutItem(Item item)
{
	printf("%d, ", item);
}

void randomQueueIterator()
{
	for (randomQueueEntry *tmp = randomQueueHead->next; !tmp; tmp = tmp->next) {
		outPutItem(tmp->item);
	}
	printf("\n");
}
