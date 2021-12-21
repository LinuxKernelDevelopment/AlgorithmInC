#include <stdlib.h>
#include <stdio.h>

int ***malloc3d(int r, int c, int t)
{
	int i, j, k;
	int ***arr3d = malloc(r * sizeof(int **));
	for (i = 0; i < r; i++) {
		arr3d[i] = malloc(c * sizeof(int *));
		for (j = 0; j < c; j++)
			arr3d[i][j] = malloc(t * sizeof(int));
	}
	return arr3d;
}

int main(int argc, char *argv[])
{
	int ***arr3d = malloc3d(10, 10, 10);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				arr3d[i][j][k] = 0;

	for (int i = 0; i < 10; i++) {
		printf("\n\n");
		for (int j = 0; j < 10; j++) {
			printf("\n");
			for (int k = 0; k < 10; k++)
				printf("%d ", arr3d[i][j][k]);
		}
	}
	return 0;
}
