#include <stdio.h>
#include <stdlib.h>
typedef struct node *link;
struct node
{ int v; link next; };

link NEW(int v, link next)
{ link x = malloc(sizeof *x);
  x->v = v; x->next = next;
  return x;
}

int isConnect(link *adj, int i, int j)
{
	int connect = 0;
	link tmp = adj[i];
	while (tmp) {
		if (tmp->v == j) {
			connect = 1;
			break;
		}
		tmp = tmp->next;
	}
	return connect;
}

int indirectConnectNum(link *adj, int i, int j, int V)
{
	int num = 0;
	for (int k = 0; k < V; k++) {
		if (k == i || k == j)
			continue;
		if (isConnect(adj, k, i) && isConnect(adj, k, j))
			num++;
	}
	return num;
}

int main(int argc, char *argv[])
{
	int i, j, V;
	link *adj;

	V = atoi(argv[1]);
	adj = malloc(V * sizeof(link));

	for (i = 0; i < V; i++)
		adj[i] = NULL;

	while (scanf("%d %d\n", &i, &j) == 2)
	{
		adj[j] = NEW(i, adj[j]);
		adj[i] = NEW(j, adj[i]);
	}

	printf("indirect num:%d\n", indirectConnectNum(adj, 0, 5, V));
	return 0;
}
