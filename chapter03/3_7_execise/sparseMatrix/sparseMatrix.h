struct elem {
	int val;
	struct elem *rowNext;
	struct elem *colNext;
};

struct sparseMatrix {
	struct elem *row;
	struct elem *col;
	int rowNum;
	int colNum;
};

void dumpMatrixArray(int **matrix, int r, int c);
struct sparseMatrix *sparseMatrixInit(int **MatrixArray, int row, int col);
void dumpSparseMatrix(struct sparseMatrix *sMatrix);
