#include <stdio.h>

char **nbit_arr;
void init_nbit(int nbit)
{
	int nentry = 1 << nbit;

	nbit_arr = malloc(sizeof(char *) * nentry);

	for (i = 0; i < nentry; i++) {
		nbit_arr[i] = malloc(sizeof(char) * (nentry + 1));
		nbit_arr[i][nbit] = '\0';
	}
}

void fillnbit(int nbit, int sn)
{
	int nentry = 1 << nbit, i;

	for (i = 0; i < (1 << (nbit - 1)); i++) {
		nbit_arr[i][sn] = '0';
	}

	for (i = (1 << (nbit - 1)); i < (1 << nbit); i++) {
		nbit_arr[i][sn] = '1';
	}

	fillnbit(nbit - 1, sn + 1);


int main(int argc, char *argv)
{
	int nbit = argv[1];

	init_nbit(nbit);
	fillnbit(nbit, 0);

	return 0;
}
