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

int distance(link p, link q)
{
	int num = 0;
	for (link t = p; t != q; t = t->next, num++);
	return num;
}

int main(int argc, char *argv[])
{
	int num, dis;
	srand(time(NULL));
	int N = rand() % 10000;
	sleep(1);
	srand(time(NULL));
	int M = rand() % 100000;
	sleep(1);
	srand(time(NULL));
	int O = rand() % 100000;
	link t = malloc(sizeof *t), x = t;
	t->item = 1; t->next = t;
	for (int i = 2; i <= N; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i; x-> next = t;
	}

	link p = t;
	for (int i = 0; i < M; i++, p = p->next);
	link q = t;
	for (int i = 0; i < O; i++, q = q->next);

	num = count_num(t);
	printf("N:%d\n", N);
	printf("num:%d\n", num);

	printf("============================================\n");
	printf("M:%d, O:%d\n", M, O);
	dis = distance(p, q);
	printf("distance:%d\n", dis);
	return 0;
}
