#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
struct node { int item; link next; };

link newRandomList(int num)
{
	link t = malloc(sizeof *t), x = t;
	for (int i = 0; i < num; i++) {
		x = (x->next = malloc(sizeof *x));
		x->item = i; x->next = t;
	}
	return t;
}

void dumpList(link head, char *message)
{
	printf("message:");
	link t = head->next;
	if (t == head) {
		printf("null\n");
		return;
	}
	while (t != head) {
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");
}

int moveList(link t, link x) {
	if (t->next == t) {
		printf("t is empty\n");
		return 0;
	}
	link t1 = t->next;
	while (t1->next != t)
		t1 = t1->next;
	printf("%d\n", t1->item);
	
	t1->next = x->next;
	x->next = t;

	return 0;
}

int main(int argc, char *argv[])
{
	int len1 = atoi(argv[1]);
	int len2 = atoi(argv[2]);
	link t = newRandomList(len1);
	link x = newRandomList(len2);
	dumpList(t, "list t:");
	dumpList(x, "list x:");
	moveList(t, x);
	dumpList(t, "list t:");
	dumpList(x, "list x:");
	return 0;
}
