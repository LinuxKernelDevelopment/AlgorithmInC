#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int Item;
#define key(A)	(A)
#define	less(A, B) (key(A) < key(B))
#define	exch(A, B) { Item t = A; A = B; B = t; }
#define	compexch(A, B) if (less(B, A)) exch(A, B)

void sort(Item a[], int l, int r)
{
	int i, j;
	for (i = l + 1; i <= r; i++)
	    for (j = i; j > l; j--)
  	        compexch(a[j-1], a[j]);
}

int randomArr(int **arr)
{
	int num, i;
	int *array;

	time_t seed = time(NULL);
	srand(seed);
	num = rand() % 1000000;
	array = malloc(sizeof(int) * num);

	for (i = 0; i < num; i++)
		array[i] = rand();

	*arr = array;
	return num;
}

void perfDrive(void)
{
	int num, i;
	int *arr;
	struct timespec start, end;


	num = randomArr(&arr);

	clock_gettime(CLOCK_REALTIME, &start);
	sort(arr, 0, num - 1);
	clock_gettime(CLOCK_REALTIME, &end);

	printf("%ld\n", (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec));
	//for (i = 0; i < num; i++)
		//printf("%d\n", arr[i]);
	free(arr);
}

int main(void)
{
	perfDrive();
	return 0;
}
