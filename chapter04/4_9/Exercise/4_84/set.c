#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct set *Set;
struct set {
	int M;
	int *array;
};

Set setInit(int M)
{
	Set s;

	s = malloc(sizeof *s);
	assert(s);
	s->array = calloc(sizeof(char), M);
	assert(s->array);
	memset(s->array, 0, M * sizeof(char));
	s->M = M;
	return s;
}

void setEnter(Set a, int c)
{
	a->array[c] = 1;
}

Set setUnion(Set a, Set b)
{
	int M = a->M, i;
	Set s;

	s = setInit(M);
	for (i = 0; i < M; i++) {
		if (a->array[i] || b->array[i])
			setEnter(s, i);
	}
	return s;
}

Set setIntersection(Set a, Set b)
{
	int M = a->M, i;
	Set s;

	s = setInit(M);
	for (i = 0; i < M; i++) {
		if (a->array[i] && b->array[i])
			setEnter(s, i);
	}
	return s;
}

Set setComplement(Set a)
{
	int M = a->M, i;
	Set s ;

	s = setInit(M);
	for (i = 0; i < M; i++) {
		if (!a->array[i])
			setEnter(s, i);
	}
	return s;
}

Set setDifference(Set a, Set b)
{
	int M = a->M, i;
	Set s;

	s = setInit(M);
	for (i = 0; i < M; i++) {
		if (a->array[i] && !b->array[i])
			setEnter(s, i);
	}
	return s;
}

void printSet(Set a)
{
	int i, M = a->M;

	for (i = 0; i < M; i++) {
		if (a->array[i])
			printf("%d", i);
		if (a->array[i] && i != M - 1)
			printf(", ");
	}
	printf("\n");
}
