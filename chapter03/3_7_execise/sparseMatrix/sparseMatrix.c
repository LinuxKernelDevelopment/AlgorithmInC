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

struct sparseMatrix *sparseMatrixMultiply(struct sparseMatrix *ma, struct sparseMatrix *mb)
{
	int i = 0, j = 0, k = 0;

	struct elem **maColTmp;
	struct elem **mbRowTmp;

	maColTmp = malloc(ma->colNum * sizeof(struct elem *));
	for (int i = 0; i < ma->colNum; i++) {
		maColTmp[i] = &(ma->col[i]);
	}

	mbRowTmp = malloc(mb->rowNum * sizeof(struct elem *));
	for (int i = 0; i < mb->rowNum; i++) {
		mbRowTmp[i] = &(mb->row[i]);
	}


	struct sparseMatrix *rMatrix = malloc(sizeof(struct sparseMatrix));
	rMatrix->row = malloc(ma->rowNum * sizeof(struct elem));
	rMatrix->col = malloc(mb->colNum * sizeof(struct elem));
	for (int i = 0; i < ma->rowNum; i++) {
		rMatrix->row[i].rowNext = NULL;
		rMatrix->row[i].colNext = NULL;
	}
	for (int i = 0; i < mb->colNum; i++) {
		rMatrix->col[i].rowNext = NULL;
		rMatrix->col[i].colNext = NULL;
	}
	rMatrix->rowNum = ma->rowNum;
	rMatrix->colNum = mb->colNum;

	struct elem **rrowtmp = malloc(rMatrix->rowNum * sizeof(struct elem*));
	struct elem **rcoltmp = malloc(rMatrix->colNum * sizeof(struct elem*));
	for (int i = 0; i < rMatrix->rowNum; i++) {
		rrowtmp[i] = &(rMatrix->row[i]);
	}
	for (int i = 0; i < rMatrix->colNum; i++) {
		rcoltmp[i] = &(rMatrix->col[i]);
	}

	for (i = 0; i < ma->rowNum; i++) {
		for (j = 0; j < mb->colNum; j++) {
			int sum = 0;
			struct elem *rowTmp = ma->row[i].rowNext;
			struct elem *colTmp = mb->col[j].colNext;
			for (k = 0; k < ma->colNum; k++) {
				if (rowTmp == maColTmp[k]->colNext &&
					colTmp == mbRowTmp[k]->rowNext) {
					sum += rowTmp->val * colTmp->val;
					//maColTmp[k] = maColTmp[k]->colNext;
					mbRowTmp[k] = mbRowTmp[k]->rowNext;
					rowTmp = rowTmp->rowNext;
					colTmp = colTmp->colNext;
				} else if (rowTmp == maColTmp[k]->colNext) {
					//maColTmp[k] = maColTmp[k]->colNext;
					rowTmp = rowTmp->rowNext;
				} else if (colTmp = mbRowTmp[j]->rowNext) {
					mbRowTmp[j] = mbRowTmp[j]->rowNext;
					colTmp = colTmp->colNext;
				}
			}
			if (sum) {
				struct elem *t = malloc(sizeof(struct elem));
				t->val = sum;
				t->rowNext = NULL;
				t->colNext = NULL;
				rrowtmp[i]->rowNext = t;
				rcoltmp[j]->colNext = t;
				rrowtmp[i] = rrowtmp[i]->rowNext;
				rcoltmp[j] = rcoltmp[j]->colNext;
			}
		}
		struct elem *rowTmp = ma->row[i].rowNext;
		for (k = 0; k < ma->colNum; k++) {
			if (rowTmp == maColTmp[k]->colNext) {
			       maColTmp[k] = maColTmp[k]->colNext;
			       rowTmp = rowTmp->rowNext;
		        }	       
		}
		struct elem *colTmp = mb->col[j].colNext;
		for (k = 0; k < mb->rowNum; k++) {
			if (colTmp == mbRowTmp[k]->rowNext) {
				mbRowTmp[k] = mbRowTmp[k]->rowNext;
				colTmp = colTmp->colNext;
			}
		}
	}
	return rMatrix;
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
