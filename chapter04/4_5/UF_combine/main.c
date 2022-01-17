#include <stdio.h>
#include "UF.h"

int main(int argc, char *argv[])
{
	int p, q, N = atoi(argv[1]);
	UFinit(N);
	while (scanf("%d %d", &p, &q) == 2)
	{ UFunion_combine(p, q); }
	rewind(stdin);
	scanf("%d %d", &p, &q);
	if (UFfind(p, q)) {
		printf("connected\n");
	}
	return 0;
}
