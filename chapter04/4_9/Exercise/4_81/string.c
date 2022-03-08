#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct string *String;
struct string {
	char *str;
	int slen;
};

String StringInit(char *str)
{
	int len;
	String s;

	s = malloc(sizeof *s);
	assert(s);
	len = strlen(str);
	s->str = malloc(sizeof(char) * (len + 1));
	assert(s->str);
	strcpy(s->str, str);
	s->str[len] = '\0';
	s->slen = len;

	return s;
}

void StringDestroy(String a)
{
	free(a->str);
	free(a);
}

int StringCmp(String a, String b)
{
	return strcmp(a->str, b->str);
}

String StringCat(String a, String b)
{
	String s;
	int slen;

	slen = strlen(a->str) + strlen(b->str);
	s = malloc(sizeof *s);
	assert(s);
	s->str = malloc(slen + 1);
	assert(s->str);
	memcpy(s->str, a->str, a->slen);
	memcpy(s->str + a->slen, b->str, b->slen);
	return s;
}

String StringCopy(String a, String b)
{
	if (b->slen > a->slen) {
		a->str = realloc(a->str, b->slen);
	}
	a->slen = b->slen;
	memcpy(a->str, b->str, b->slen);
	a->str[b->slen] = '\0';
	return a;
}

int StringLen(String a)
{
	return a->slen;
}

void StringPrint(String a)
{
	printf("%s\n", a->str);
}
