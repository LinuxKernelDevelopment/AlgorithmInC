#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "randomQueue.h"

int main(int argc, char *argv[])
{
	int i;
	randomQueueInit(1);
	int N = atoi(argv[1]);
	for (i = 0; i < N; i++) {
		randomQueueEnqueue(i);
	}

	for (i = 0; i < 5; i++) {
		printf("%d ", randomQueueDequeue());
	}
	printf("\n");
	return 0;
}
