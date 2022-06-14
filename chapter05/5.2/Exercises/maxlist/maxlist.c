#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node { int item; link next; };

link initList(int a[], int n)
{
	int i;
	link t = malloc(sizeof *t), x = t;
	t->item = a[0]; t->next = NULL;

	for (i = 1; i < n; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = a[i]; x->next = NULL;
	}

	return t;
}

int maxList(link t)
{
	int max;

	if (t->next == NULL)
		return t->item;

	max = maxList(t->next);
	if (t->item > max)
		return t->item;
	else
		return max;
}

int main(void)
{
	link t;
	int a[] = {87, 2837, 2367, 876934, 8937, 389, 389, 432, 468 };

	t = initList(a, sizeof(a) / sizeof(int));
	printf("%d\n", maxList(t));
	return 0;
}
