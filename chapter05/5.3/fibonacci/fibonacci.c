#include <stdio.h>
#include <stdlib.h>

int *knownF;
#define unknown -1

int F(int i)
{
	int t;
	if (knownF[i] != unknown)
		return knownF[i];
	if (i == 0)
		t = 0;
	if (i == 1)
		t = 1;
	if (i > 1)
		t = F(i-1) + F(i-2);
	return knownF[i] = t;
}

int main(int argc, char *argv[])
{
	int i = atoi(argv[1]);

	knownF = malloc(sizeof(int) * (i + 1));
	for (int j = 0; j < i + 1; j++)
		knownF[j] = unknown;

	printf("i:%d, F:%d\n", i, F(i));
	return 0;
}
