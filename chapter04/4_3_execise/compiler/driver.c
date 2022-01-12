#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"

int main(int argc, char *argv[])
{
	char *line = NULL, *buf = NULL;
	size_t n;
	initSymbolTable();
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen failed");
		exit(-1);
	}
	while (getline(&line, &n, fp) != -1) {
		buf = infixToPostfix(line);
		evalPostfix(buf);
	}
	return 0;
}
