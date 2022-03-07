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
		for (j = 0; j < col; j++) {
			c->ma[i][j] = malloc(sizeof(int));
			assert(c->ma[i][j]);
		}
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

MA matriceAddition(MA a, MA b)
{
	int i, j;
	MA c;
	assert(a->row == b->row && a->col == b->col);
	
	c = allocMatric(a->row, a->col);
	for (i = 0; i < a->row; i++) {
		for (j = 0; j < a->col; j++) {
			c->ma[i][j] = a->ma[i][j] + b->ma[i][j];
		}
	}
	c->row = a->row;
	c->col = a->col;
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
