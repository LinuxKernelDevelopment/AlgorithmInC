#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct matrice *MA;
struct matrice {
	int row;
	int col;
	int **ma;
};

static MA allocMatric(int row, int col)
{
	int i, j;
	MA c = malloc(sizeof *c);
	assert(c);
	c->ma = malloc(sizeof(int *) * row);
	assert(c->ma);
	for (i = 0; i < row; i++) {
		c->ma[i] = malloc(sizeof(int) * col);
		assert(c->ma[i]);
	}
	return c;
}

MA initMatrice(int *a, int row, int col)
{
	int i, j;

	MA c = allocMatric(row, col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			c->ma[i][j] = *(a + i * col + j);
	}
	c->row = row;
	c->col = col;
	return c;
}

void destroyMatrice(MA a)
{
	int i;
	for (i = 0; i < a->row; i++)
		free(a->ma[i]);
	free(a->ma);
}

MA matriceAddSub(MA a, MA b, int addFlag)
{
	int i, j;
	MA c;
	assert(a->row == b->row && a->col == b->col);
	
	c = allocMatric(a->row, a->col);
	for (i = 0; i < a->row; i++) {
		for (j = 0; j < a->col; j++) {
			if (addFlag)
				c->ma[i][j] = a->ma[i][j] + b->ma[i][j];
			else
				c->ma[i][j] = a->ma[i][j] - b->ma[i][j];
		}
	}
	c->row = a->row;
	c->col = a->col;
	return c;
}

MA matriceMul(MA a, MA b)
{
	MA c;
	int sum = 0, i, j, k;
	assert(a->row == b->col);

	c = allocMatric(a->row, b->col);
	for (i = 0; i < a->row; i++) {
		for (j = 0; j < b->col; j++) {
			for (k = 0; k < b->row; k++)
				sum += a->ma[i][k] * b->ma[k][j];
			c->ma[i][j] = sum;
			sum = 0;
		}
	}
	c->row = a->row;
	c->col = b->col;
	return c;
}

MA matriceDiv(MA a, int b)
{
	MA c;
	int i, j;

	c = allocMatric(a->row, a->col);
	c->row = a->row;
	c->col = a->col;
	for (i = 0; i < a->row; i++) {
		for (j = 0; j < a->col; j++) {
			c->ma[i][j] = a->ma[i][j] / b;
		}
	}
	return c;
}

void printMatrice(MA a)
{
	int i, j;
	for (i = 0; i < a->row; i++) {
		for (j = 0; j < a->col; j++) {
			printf("%d\t", a->ma[i][j]);
		}
		printf("\n");
	}
}
