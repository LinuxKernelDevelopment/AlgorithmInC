#include <stdio.h>
#include <stdlib.h>

int gcd(int i, int j)
{
	if (j == 0)
		return i;
	else
		return gcd(j, i % j);
}

int main(int argc, char *argv[])
{
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	int **arr = calloc(row * sizeof(int *), 1);
	for (int i = 0; i < row; i++)
		arr[i] = malloc(col * sizeof(int));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gcd(i, j) == 1)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}

	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col; j++)
			printf("%d ", arr[i][j]);
	}
	return 0;
}
