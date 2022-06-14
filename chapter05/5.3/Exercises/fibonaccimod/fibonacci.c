#include <stdio.h>
#include <stdlib.h>

int *knownF;
int *knownFM;
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

int FM(int i, int M)
{
	int t;
	if (knownFM[i] != unknown)
		return knownFM[i];
	if (i == 0)
		t = 0;
	if (i == 1)
		t = 1;
	if (i > 1)
		t = FM(i-1, M) + FM(i-2, M);
	return knownFM[i] = t % M;
}

int main(int argc, char *argv[])
{
	int i = atoi(argv[1]);
	int M = atoi(argv[2]);

	knownF = malloc(sizeof(int) * (i + 1));
	for (int j = 0; j < i + 1; j++)
		knownF[j] = unknown;

	knownFM = malloc(sizeof(int) * (i + 1));
	for (int j = 0; j < i + 1; j++)
		knownFM[j] = unknown;
	printf("i:%d, F:%d\n", i, F(i));

	printf("i:%d, FM:%d\n", i, FM(i, M));

	return 0;
}
