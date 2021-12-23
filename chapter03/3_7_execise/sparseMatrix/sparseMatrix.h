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


