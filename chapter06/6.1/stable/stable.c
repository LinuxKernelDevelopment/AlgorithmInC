#include <stdio.h>
#include <stdlib.h>

int **markArray(int *a, int num)
{
	int i;
	int **mark = malloc(sizeof(int *) * num);
	if (!mark) {
		perror("malloc failed");
		exit(-1);
	}
	for (i = 0; i < num; i++)
		mark[i] = &a[i];
	return mark;
}

int findIdx(int **mark, int *elem, int num)
{
	int i;

	for (i = 0; i < num; i++) {
		if (mark[i] == elem)
			break;
	}
	return i;
}

int stable(int *a, int **mark, int num)
{
	int low = 0, high = 0, idx, prevIdx, i;
	while (low < num) {
		for (i = low; i < num; i++) {
			if (a[i] < a[i+1]) {
				high = i + 1;
				break;
			}
		}
		for (i = low; i < high; i++) {
			idx = findIdx(mark, a, num);
			if (prevIdx < idx)
				return 0;
			prevIdx = idx;
		}
	}
	return 1;
}
