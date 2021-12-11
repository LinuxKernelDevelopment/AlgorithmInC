#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct node* link;
struct node { int item; link next; };

int count_num(link head)
{
	int num = 0;
	link t = head;
	if (head == NULL)
		return 0;
	t = t->next; num++;
	while (t != head) {
		t = t->next;
		num++;
	}
	return num;
}

int main(int argc, char *argv[])
{
	int num;
	srand(time(NULL));
	int N = rand() % 10000;
	link t = malloc(sizeof *t), x = t;
	t->item = 1; t->next = t;
	for (int i = 2; i <= N; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i; x-> next = t;
	}

	num = count_num(t);
	printf("N:%d\n", N);
	printf("num:%d\n", num);
	return 0;
}
