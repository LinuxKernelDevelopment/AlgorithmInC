#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "random.h"

int isLoop(link nodeSet, int setNum, link pa, link pb)
{
	for (int i = 0;;i++) {
		pa = pa->next;
		pb = pb->next->next;
		if (pa == pb)
			return 1;
		if (i > 2 * setNum)
			return 0;
	}
}

int countLoop(link nodeSet, int setNum, link pa, link pb)
{
	int i;
	link pat = pa;
	link pbt = pb;
	for (i = 0;;i++) {
		pat = pat->next;
		pbt = pbt->next->next;
		if (pat == pbt)
			break;
		if (i > 2 * setNum)
			return 0;
	}
	return i;
}

int main(int argc, char *argv[])
{
	int setNum = atoi(argv[1]);
	link nodeSet = malloc(sizeof(*nodeSet) * setNum);
	if (!nodeSet) {
		fprintf(stderr, "malloc failed\n");
		exit(-1);
	}
	for (int i = 0; i < setNum; i++) {
		nodeSet[i].item = i;
		nodeSet[i].next = &nodeSet[getUint32() % setNum];
	}
	printf("%d\n", isLoop(nodeSet, setNum, &nodeSet[0], &nodeSet[50]));
	printf("%d\n", countLoop(nodeSet, setNum, &nodeSet[0], &nodeSet[50]));
	return 0;
}
