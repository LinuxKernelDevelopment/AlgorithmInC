#include <stdio.h>
#include <stdlib.h>

int hanoi(int num)
{
	int r;
	int t, j, i, inter, stripe;

	int numMov = (1 << num) - 1;
	int *move = malloc(numMov * sizeof(int));
	if (!move) {
		printf("malloc failed\n");
		exit(-1);
	}
	
	for (t = 1, j = 1, stripe = 1 << j; t <= num;
		j++, stripe = 1 << j, t++)
		for (i = (1 << (t - 1)) - 1; i <= numMov; i += stripe)
			move[i] = (t % 2) ? t : (-t);


	for (int i = 0; i < numMov; i++)
		printf("%s%d\n", move[i] > 0 ? "+" : "", move[i]);
	return 0;
}

int main(int argc, char *argv[])
{
	int num = atoi(argv[1]);
	hanoi(num);
	return 0;
}
