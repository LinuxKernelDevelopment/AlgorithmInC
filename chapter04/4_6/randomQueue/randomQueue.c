#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "Item.h"
#include "hash.h"
#include "randomQueue.h"
#include "random.h"


randomQueueEntry *randomQueue;
int randomQueueSizeVar = 0;
int randomQueueIdx = 0;
int randomQueueHeadIdx = -1;

extern int hashEntryCnt;

void randomQueueInit(int maxN)
{
	randomQueue = memalign(4096, sizeof(randomQueueEntry) * maxN);
	memset(randomQueue, 0, sizeof(randomQueueEntry) * maxN);
	randomQueueSizeVar = 0;
	hashInit(10);
}

int randomQueueIsEmpty()
{
	return randomQueueSizeVar == 0;
}

int randomQueueSize()
{
	return randomQueueSizeVar;
}

void randomQueueEnqueue(Item item)
{
	randomQueueEntry *lastEntry, *newEntry;
	if (randomQueueHeadIdx == -1) {
		randomQueueHeadIdx = randomQueueIdx;
		assert(randomQueue[randomQueueIdx].used == 0);
		newEntry = &randomQueue[randomQueueIdx];
		newEntry->prevIdx = NULL_ENTRY;
		newEntry->nextIdx = NULL_ENTRY;
		newEntry->used = 1;
		newEntry->item = item;
		randomQueueSizeVar++;
		return;
	} else {
		assert(randomQueue[randomQueueIdx].used == 1);
		lastEntry = &randomQueue[randomQueueIdx];
		randomQueueIdx += 1;
	}
	int lastIdx = lastEntry - randomQueue;
	lastEntry->nextIdx = randomQueueIdx;
	newEntry = &randomQueue[randomQueueIdx];
	assert(randomQueue[randomQueueIdx].used == 0);
	newEntry->nextIdx = NULL_ENTRY;
	newEntry->prevIdx = lastIdx;
	newEntry->item = item;
	newEntry->used = 1;
	randomQueueSizeVar++;
}

Item randomQueueDequeue()
{
	unsigned int randomNum = getUint32();
	int idx = randomNum % randomQueueSizeVar, prevIdx, nextIdx;
	Item item;
	randomQueueEntry *dequeueEntry, *prevEntry, *nextEntry;
	
	if (randomQueueSizeVar == 0) {
		fprintf(stderr, "randomQueue empty\n");
		exit(-1);
	}

	int hashNum = hashNumGet();

	while (randomQueue[idx].used == 0) {
		idx++;
		if (idx > randomQueueIdx)
			idx = 0;
	}
	dequeueEntry = &randomQueue[idx];
	prevIdx = dequeueEntry->prevIdx;
	nextIdx = dequeueEntry->nextIdx;
	if (prevIdx != NULL_ENTRY) {
		prevEntry = &randomQueue[prevIdx];
		prevEntry->nextIdx = dequeueEntry->nextIdx;
	} else {
		if (nextIdx != NULL_ENTRY)
			randomQueueHeadIdx = nextIdx;

	}
	if (nextIdx != NULL_ENTRY) {
		nextEntry = &randomQueue[nextIdx];
		nextEntry->prevIdx = dequeueEntry->prevIdx;
	}
			
	item = dequeueEntry->item;
	//memset(dequeueEntry, 0, sizeof(randomQueueEntry));
	dequeueEntry->used = 0;
	randomQueueSizeVar--;
	return item;
}

Item randomQueueSample()
{
	Item item;
	unsigned int randomNum = getUint32();
	int idx = randomNum % randomQueueIdx;
	while (randomQueue[idx].used == 0)
		idx = randomNum % randomQueueIdx;
	item = randomQueue[idx].item;
	return item;
}

void outputItem(Item item)
{
	printf("%c ", item);
}

void randomQueueIterator()
{
	int idx;
	for (idx = randomQueueHeadIdx; randomQueue[idx].used != 0; idx = randomQueue[idx].nextIdx) {
		outputItem(randomQueue[idx].item);
	}
	printf("\n");
}
