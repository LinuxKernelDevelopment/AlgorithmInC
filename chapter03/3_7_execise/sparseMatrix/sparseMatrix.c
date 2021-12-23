#include <stdlib.h>
#include <stdio.h>
#include "sparseMatrix.h"

int **malloc2d(int r, int c);

void dumpMatrixArray(int **matrix, int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

struct sparseMatrix *sparseMatrixInit(int **MatrixArray, int row, int col)
{
	struct sparseMatrix *sMatrix = malloc(sizeof(struct sparseMatrix));
	sMatrix->row = malloc(row * sizeof(struct elem));
	sMatrix->col = malloc(col * sizeof(struct elem));
	for (int i = 0; i < row; i++) {
		sMatrix->row[i].rowNext = NULL;
		sMatrix->row[i].colNext = NULL;
	}
	for (int i = 0; i < col; i++) {
		sMatrix->col[i].rowNext = NULL;
		sMatrix->col[i].colNext = NULL;
	}
	sMatrix->rowNum = row;
	sMatrix->colNum = col;

	struct elem **rowtmp = malloc(row * sizeof(struct elem *));
	struct elem **coltmp = malloc(col * sizeof(struct elem *));
	for (int i = 0; i < row; i++) {
		rowtmp[i] = &(sMatrix->row[i]);
	}
	for (int i = 0; i < col; i++) {
		coltmp[i] = &(sMatrix->col[i]);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (MatrixArray[i][j]) {
				struct elem *t = malloc(sizeof(struct elem));
				t->val = MatrixArray[i][j];
				t->rowNext = NULL;
				t->colNext = NULL;
				rowtmp[i]->rowNext = t;
				coltmp[j]->colNext = t;
				rowtmp[i] = rowtmp[i]->rowNext;
				coltmp[j] = coltmp[j]->colNext;
			}
		}
	}
	free(rowtmp);
	free(coltmp);
	return sMatrix;
}

void dumpSparseMatrix(struct sparseMatrix *sMatrix)
{
	int row = sMatrix->rowNum;
	int col = sMatrix->colNum;
	int i, j;
	struct elem **rowtmp = malloc(row * sizeof(struct elem *));
	struct elem **coltmp = malloc(col * sizeof(struct elem *));
	for (i = 0; i < row; i++) {
		rowtmp[i] = &(sMatrix->row[i]);
	}
	for (i = 0; i < col; i++) {
		coltmp[i] = &(sMatrix->col[i]);
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (rowtmp[i]->rowNext && rowtmp[i]->rowNext == coltmp[j]->colNext) {
				printf("%d\t", rowtmp[i]->rowNext->val);
				rowtmp[i] = rowtmp[i]->rowNext;
				coltmp[j] = coltmp[j]->colNext;
			} else {
				printf("%d\t", 0);
			}
		}
		printf("\n");
	}
}

int main()
{
	int row, col;
	int **arr;
	struct sparseMatrix *sMatrix;

	scanf("%d", &row);
	scanf("%d", &col);

	arr = malloc2d(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			scanf("%d", &arr[i][j]);
	}
	dumpMatrixArray(arr, row, col);
	printf("\n");

	sMatrix = sparseMatrixInit(arr, row, col);
	dumpSparseMatrix(sMatrix);
	return 0;
}
