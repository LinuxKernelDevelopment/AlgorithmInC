#include <stdlib.h>
#include <stdio.h>
#include "POLY.h"
struct poly { int N; int *a; };

Poly POLYterm(int coeff, int exp)
{
	int i; Poly t = malloc(sizeof *t);
	t->a = malloc((exp + 1) * sizeof(int));
	t->N = exp + 1; t->a[exp] = coeff;
	for (i = 0; i < exp; i++) t->a[i] = 0;
	return t;
}

Poly POLYadd(Poly p, Poly q)
{
	int i; Poly t;

	t = POLYterm(0, p->N > q->N ? p->N - 1 : q->N - 1);
	for (i = 0; i < t->N; i++)
		t->a[i] = p->a[i] + q->a[i];

	return t;
}

Poly POLYmult(Poly p, Poly q)
{
	int i,  j;
	Poly t = POLYterm(0, (p->N-1) + (q->N-1));
	for (i = 0; i < p->N; i++)
		for (j = 0; j < q->N; j++)
			t->a[i+j] += p->a[i] * q->a[j];
	return t;
}

float POLYeval(Poly p, float x)
{
	int i; double t = 0.0;
	for (i = p->N-1; i >= 0; i--)
		t = t*x + p->a[i];
	return t;
}

void showPOLY(Poly p)
{
	if (p->a[p->N-1]) {
		printf("%dx^%d", p->a[p->N-1], p->N - 1);
	}
	for (int i = p->N-2; i >= 0; i--) {
		if (p->a[i]) {
			printf(" + %dx^%d", p->a[i], i);
		}
	}
	printf("\n");
}
