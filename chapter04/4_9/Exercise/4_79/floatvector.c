#include <stdio.h>
#include <stdlib.h>

typedef struct floatVector *FV;
struct floatVector {
	float *fv;
	int num;
};

FV initFloatVector(float *p, int num)
{
	FV v = malloc(sizeof *v);
	v->fv = malloc(sizeof(float) * num);
	v->num = num;
	for (int i = 0; i < num; i++)
		v->fv[i] = p[i];
	return v;
}

void addFn(FV v, float a)
{
	for (int i = 0; i < v->num; i++)
		v->fv[i] += a;
}

void printFloatVector(FV v)
{
	for (int i = 1; i < v->num; i++) {
		printf("%f\t", v->fv[i]);
		if (i % 5 == 0)
			printf("\n");
	}
	printf("\n");
}
