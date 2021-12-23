#include <stdlib.h>
#include <stdio.h>
#include "sparseMatrix.h"

int **malloc2d(int, int);

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
