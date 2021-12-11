#include <stdlib.h>
#include <stdio.h>
#include "list.h"

link newNode(int itemValue)
{
	link t = malloc(sizeof *t);
	t->item = itemValue;
	t->next = NULL;
	return t;
}

link allocNode(int itemValue)
{
	link t = malloc(sizeof *t);
	t->item = itemValue;
	t->next = NULL;
	return t;
}

void freeNode(link t)
{
	free(t);
}

void insertNode(link x, link t)
{
	t->next = x->next;
	x->next = t;
}

void insertNoDummyNode(link *x, link t)
{
	if (*x) {
		t->next = (*x)->next;
		(*x)->next = t;
	} else
		*x = t;
}

link deleteNext(link x)
{
	if (!x) {
		fprintf(stderr, "NULL");
		exit(-1);
	}
	link t = x->next;
	x->next = t->next;
	return t;
}

link Next(link t)
{
	return t->next;
}

itemType Item(link t)
{
	return t->item;
}

link initDummyList()
{
	link head = malloc(sizeof *head);
	if (head == NULL) {
		perror("malloc failed");
		exit(-1);
	}
	return head;
}

link initNoDummyList()
{
	link head = NULL;
	return head;
}

void dumpList(link t)
{
	t = t->next;
	while (t) {
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");
}

void dumpNoDummyList(link t)
{
	while (t) {
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");
}

int exchange(link t, link u)
{
	if (t == NULL || u == NULL)
		return -1;
	if (t->next == NULL || u->next == NULL)
		return -2;
	link tNext = deleteNext(t);
	link uNext = deleteNext(u);
	insertNode(t, uNext);
	insertNode(u, tNext);
	return 0;
}

int freeList(link t)
{
	while (t) {
		link tmp = t;
		t = t->next;
		freeNode(tmp);
	}
	return 0;
}
