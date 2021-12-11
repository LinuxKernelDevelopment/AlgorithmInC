#include <stdio.h>
#include <stdlib.h>

void *chrcnt(char *input, int *chrArray)
{

	for (int i = 0; input[i] != '\0'; i++) {
		chrArray[input[i]] += 1;
	}
}

int main(int argc, char *argv[])
{
	char *input = argv[1];

	int *chrArray = malloc(sizeof(int) * 127);
	if (!chrArray) {
		fprintf(stderr, "malloc failed\n");
		exit(-1);
	}
	chrcnt(input, chrArray);
	for (int i = 65; i < 91; i++) {
		if (chrArray[i])
			printf("%c	%d\n", i, chrArray[i]);
	}
	for (int i = 97; i < 123; i++) {
		if (chrArray[i])
			printf("%c	%d\n", i, chrArray[i]);
	}
	free(chrArray);
	return 0;
}
