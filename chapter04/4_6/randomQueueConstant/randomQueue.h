#ifndef __RANDOM_QUEUE_H__

typedef struct entry {
	Item item;
	int prevIdx;
	int nextIdx;
	int used;
} randomQueueEntry;


void randomQueueInit(int);
int randomQueueIsEmpty();
int randomQueueSize();
void randomQueueEnqueue(Item item);
Item randomQueueDequeue(void);
Item randomQueueSample(void);
void randomQueueIterator(void);

#define	NULL_ENTRY	-2
#endif
