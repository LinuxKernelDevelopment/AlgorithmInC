#include <stdio.h>
#include <stdlib.h>

char **nbit_arr;
void init_nbit(int nbit)
{
	int i;
	int nentry = 1 << nbit;

	nbit_arr = malloc(sizeof(char *) * nentry);

	for (i = 0; i < nentry; i++) {
		nbit_arr[i] = malloc(sizeof(char) * (nentry + 1));
		nbit_arr[i][nbit] = '\0';
	}
}

void dump_nbit(int nentry)
{
	int i;

	for (i = 0; i < nentry; i++)
		printf("%s\n", nbit_arr[i]);
}

void fillnbit(int start, int end, int bitPos)
{
	int i, j, mid;
	if (start + 1 == end)
		return;

	mid = (start + end) / 2;
	for (i = start; i < mid; i++)
		nbit_arr[i][bitPos] = '0';

	for (j = mid; j < end; j ++)
		nbit_arr[j][bitPos] = '1';

	fillnbit(start, mid, bitPos + 1);
	fillnbit(mid, end, bitPos + 1);
}

int main(int argc, char **argv)
{
	int nbit = atoi(argv[1]);
	int nentry = 1 << nbit;

	init_nbit(nbit);
	fillnbit(0, nentry, 0);
	dump_nbit(nentry);

	return 0;
}
