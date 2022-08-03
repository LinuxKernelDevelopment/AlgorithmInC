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
	int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr2[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
	struct timespec start, end;



	sort(arr1, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d\n", arr1[i]);
	sort(arr2, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d\n", arr2[i]);

}

int main(void)
{
	perfDrive();
	return 0;
}
