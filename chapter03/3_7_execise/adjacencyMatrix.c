#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, j, V;
	int **adj;
	V = atoi(argv[1]);

	adj = malloc(sizeof(int *) * V);
	for (int i = 0; i < V; i++)
		adj[i] = malloc(sizeof(int) * V);

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			adj[i][j] = 0;

	for (i = 0; i < V; i++)
		adj[i][i] = 1;

	while (scanf("%d %d", &i, &j) == 2)
	{ adj[i][j] = 1; adj[j][i] = 1; }

	return 0;
}
