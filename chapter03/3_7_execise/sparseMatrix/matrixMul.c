#include <stdlib.h>
#include <stdio.h>
#include "sparseMatrix.h"

int **malloc2d(int, int);

int main()
{
	int row, col;
	int **arr, **arr2;
	struct sparseMatrix *aMatrix;
	struct sparseMatrix *bMatrix;
	struct sparseMatrix *cMatrix;

	scanf("%d", &row);
	scanf("%d", &col);

	arr = malloc2d(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			scanf("%d", &arr[i][j]);
	}
	dumpMatrixArray(arr, row, col);
	printf("\n");

	aMatrix = sparseMatrixInit(arr, row, col);

	scanf("%d", &row);
	scanf("%d", &col);
	arr2 = malloc2d(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			scanf("%d", &arr2[i][j]);
	}
	bMatrix = sparseMatrixInit(arr2, row, col);

	cMatrix = sparseMatrixMultiply(aMatrix, bMatrix);
	dumpSparseMatrix(aMatrix);
	printf("\n");
	dumpSparseMatrix(bMatrix);
	printf("\n");
	dumpSparseMatrix(cMatrix);
	return 0;
}
