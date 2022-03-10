#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "doubleList.h"

typedef struct string *String;
struct string {
	link head; // dummy head
	int slen;
};

String StringInit(char *str)
{
	String s;
	int i;
	link t;

	s = malloc(sizeof *s);
	assert(s);
	s->head = ListInit();
	t = s->head;
	for (i = 0; str[i] != '\0'; i++) {
		t = NEW(str[i], t);
	}
	s->slen = i;
	return s;
}

void StringDestroy(String a)
{
	link t = a->head;
	ListDestroy(t);
	free(a);
}

int StringCmp(String a, String b)
{
	return ListCmp(a->head, b->head);
}

String StringCopy(String a, String b)
{
	link t = b->head;
	link q;
	ListDestroy(a->head);
	a->head = ListInit();
	q = a->head;

	while (t) {
		Item c = ListNextVal(&t);
		q = NEW(c, q);
	}
	a->slen = b->slen;
	return a;	
}

String StringCat(String a, String b)
{
	String c = StringInit("");
	StringCopy(c, a);
	ListLinkTail(c->head, b->head);

	return c;
}

/*String StringCopy(String a, String b)
{
	link t = a->head;
	while (t->head) {
		tmp = DEL(t);
		free(tmp);
	}

	t = a->head;
	for (p = b->head.next; p != NULL; p = p->next) {
		NEW(p->item, t);
		t = t->next;
	}
	a->slen = b->slen;
	return a;
}*/

int StringLen(String a)
{
	return a->slen;
}

void printChar(char c)
{
	printf("%c", c);
}

void StringPrint(String a)
{
	ListFun(a->head, printChar);
	printf("\n");
}
