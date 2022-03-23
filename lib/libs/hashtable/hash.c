#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "item.h"
#include "hash.h"

typedef struct {
	Item item;
	int used;
} hashEntry;

hashEntry *hashTable;
int hashNum = 0;
int hashEntryCnt = 0;

int hashNumGet()
{
	return hashNum;
}

static int hashTableRealloc(int Num) 
{
	hashEntry *newHashTable = memalign(4096, sizeof(hashEntry) * Num);
	if (!newHashTable) {
		perror("memalign failed");
		exit(-1);
	}
	memset(newHashTable, 0, sizeof(hashEntry) * Num);
	memcpy(newHashTable, hashTable, sizeof(hashEntry) *Num);
	free(hashTable);
	hashTable = newHashTable;
	hashNum = Num;
	return 0;
}

void hashInit(int Num)
{
	hashTable = memalign(4096, sizeof(hashEntry) * Num);
	if (!hashTable) {
		perror("memalign failed");
		exit(-1);
	}
	hashNum = Num;
}

int hashPut(Item item, int (*hashfun)(Item))
{
	int idx = hashfun(item) % hashNum;
	if (hashEntryCnt >= hashNum / 5 * 4 && hashNum > 10)
		hashTableRealloc(hashEntryCnt / 3 * 4);
	else if (hashEntryCnt <= hashNum / 10 * 7 && hashNum > 10)
		hashTableRealloc(hashEntryCnt / 3 * 4);
	hashTable[idx].item = item;
	hashTable[idx].used = 1;
	hashEntryCnt += 1;
	return idx;
}

Item hashGet(unsigned int key)
{
	hashEntry *tmp;
	hashEntry *entry = &hashTable[key % hashNum];
	for (tmp = entry+1; tmp != entry; tmp++) {
		if (tmp == hashTable + hashNum + 1)
			tmp = hashTable;
		if (tmp->used == 1)
			break;
	}
	tmp->used = 0;
	return tmp->item;
}
