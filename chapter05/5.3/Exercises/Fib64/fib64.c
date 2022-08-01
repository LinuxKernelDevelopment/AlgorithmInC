#include <stdio.h>
#include <stdlib.h>


#define	int64_t	long long int
int64_t *knownF;
#define	unknown	-1

int64_t Fib(int64_t i)
{
	int64_t t;
	if (knownF[i] != unknown)
		return knownF[i];

	if (i == 0)
		t = 0;
	if (i == 1)
		t = 1;
	if (i > 1)
		t = Fib(i-1) + Fib(i-2);
	return knownF[i] = t;
}

int main(void)
{
	int i;
	int64_t t;

	knownF = malloc(sizeof(int64_t) * 1000);
	if (knownF == NULL) {
		perror("malloc");
		exit (-1);
	}

	for (i = 0; i < 1000; i++)
		knownF[i] = unknown;
	for (i = 0; i < 1000; i++) {
		if (Fib(i) < 0) {
			t = Fib(i-1);
			break;
		}
	}

	printf("i:%d\tlarget:%lld\n", i, t);
	free(knownF);
	return 0;
}
