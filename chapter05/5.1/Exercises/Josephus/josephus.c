#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node { int item; link next; };

link initJosephus(int N)
{
	int i;
	link t = malloc(sizeof *t), x = t;
	t->item = 1; t->next = t;
	for (i = 2; i <= N; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i; x->next = t;
	}

	return x;
}

link Josephus(link t, int M)
{
	link tmp;
	int i;

	if (t->next == t)
		return t;
	for (i = 1; i < M; i++) t = t->next;
	tmp = t->next;
	t->next = t->next->next;
	free(tmp);
	return Josephus(t, M);

}

int main(int argc, char *argv[])
{
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	link t = initJosephus(N);

	link r = Josephus(t, M);

	printf("%d\n", r->item);
	return 0;
}
