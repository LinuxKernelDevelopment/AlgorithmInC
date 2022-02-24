#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "POLY.h"

typedef struct node *polyNode;
struct node {
	float coeff;
	float exp;
	polyNode next;
};

struct poly {
	struct node polyHead;   //dummy head
};

Poly POLYterm(int coeff, int exp)
{
	polyNode t = malloc(sizeof *t);
	t->coeff = coeff;
	t->exp = exp;
	t->next = NULL;

	Poly p = malloc(sizeof *p);
	p->polyHead.next = t;
	return p;
}

static polyNode removeFactor(Poly p)
{
	polyNode t;

	t = p->polyHead.next;
	if (t)
		p->polyHead.next = t->next;

	return t;
}

static void insertFactor(Poly p, polyNode t)
{
	polyNode prev = &p->polyHead;
	polyNode tmp = prev->next;

	while (tmp) {
		if (t->exp > tmp->exp)
			break;
		tmp = tmp->next;
		prev = prev->next;
	}
	t->next = tmp;
	prev->next = t;
}

static void addFactor(Poly p, polyNode t)
{
	polyNode prev = &p->polyHead;
	polyNode tmp = prev->next;

	while (tmp) {
		if (t->exp == tmp->exp) {
			tmp->coeff += t->coeff;
			return;
		} else if (t->exp > tmp->exp) {
			break;
		}
		tmp = tmp->next;
		prev = prev->next;
	}
	t->next = tmp;
	prev->next = t;
}

Poly POLYadd(Poly p, Poly q)
{
	polyNode t;

	assert(p->polyHead.next && q->polyHead.next);
	while (t = removeFactor(q)) {
		addFactor(p, t);
	}
	return p;
}

static int factorNum(Poly p)
{
	int num = 0;
	polyNode t = p->polyHead.next;

	while (t) {
		num += 1;
		t = t->next;
	}
	return num;
}

Poly POLYmult(Poly p, Poly q)
{
	int idx, i;
	Poly sum;
	int numFactor = factorNum(q);

	Poly *tmp = malloc(sizeof(Poly) * numFactor);
	if (!tmp) {
		perror("malloc failed");
		exit(-1);
	}
	for (i = 0; i < numFactor; i++)
		tmp[i] = malloc(sizeof(struct poly));

	polyNode qfactor, pfactor;
	idx = 0;
	for (qfactor = q->polyHead.next; qfactor != NULL; qfactor = qfactor->next) {
		for (pfactor = p->polyHead.next; pfactor != NULL; pfactor = pfactor->next) {
			polyNode tmpNode = malloc(sizeof *tmpNode);
			tmpNode->coeff = qfactor->coeff * pfactor->coeff;
			tmpNode->exp = qfactor->exp + pfactor->exp;
			tmpNode->next = NULL;
			insertFactor(tmp[idx], tmpNode);
		}
		idx += 1;
	}
	sum = tmp[0];

	for (i = 1; i < numFactor; i++)
		sum = POLYadd(sum, tmp[i]);

	return sum;
}

Poly POLYintegral(Poly p)
{
	Poly integral;
	polyNode t;

	integral = malloc(sizeof(struct poly));
	for (t = p->polyHead.next; t != NULL; t = t->next) {
		polyNode tmpNode = malloc(sizeof *tmpNode);
		tmpNode->coeff = t->coeff / (t->exp + 1);
		tmpNode->exp = t->exp + 1;
		tmpNode->next = NULL;
		insertFactor(integral, tmpNode);
	}
	return integral;
}

Poly POLYdiff(Poly p)
{
	Poly diff;
	polyNode t;

	diff = malloc(sizeof(struct poly));
	for (t = p->polyHead.next; t != NULL; t = t->next) {
		if (t->exp == 0)
			continue;

		polyNode tmpNode = malloc(sizeof *tmpNode);
		tmpNode->coeff = t->coeff * t->exp;
		tmpNode->exp = t->exp - 1;
		tmpNode->next = NULL;
		insertFactor(diff, tmpNode);
	}
	return diff;
}

void showPOLY(Poly p)
{
	polyNode t = p->polyHead.next;

	assert(t);
	printf("%fx^%f", t->coeff, t->exp);

	t = t->next;

	while (t) {
		if (t->exp)
			printf(" + %fx^%f", t->coeff, t->exp);
		else
			printf(" + %f", t->coeff);
		t = t->next;
	}
	printf("\n");
}
