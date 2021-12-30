#include <stdio.h>
#include <stdlib.h>

int isConnect(int **adj, int i, int j)
{
	return adj[i][j] == 1;
}

int indirectConnectNum(int **adj, int i, int j, int V)
{
	int num = 0;
	for (int k = 0; k < V; k++) {
		if (k == i || k == j)
			continue;
		if (isConnect(adj, k, i) && isConnect(adj, k, j)) {
			num++;
		}
	}
	return num;
}

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

	printf("indirect num:%d\n", indirectConnectNum(adj, 0, 5, V));
	return 0;
}
