#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

void processBuf(char *buf, size_t n)
{
	QUEUEinit(n);
	for (int i = 0; i < n; i++) {
		if (buf[i] >= 'A' && buf[i] <= 'Z') 
			QUEUEputHead(buf[i]);

		if (buf[i] >= 'a' && buf[i] <= 'z')
			QUEUEput(buf[i]);

		if (buf[i] == '*')
			printf("%c ", QUEUEgetTail());

		if (buf[i] == '+')
			printf("%c ", QUEUEget());
	}
}

int main(int argc, char *argv[])
{
	char *buf;
	size_t n;
	ssize_t ret;
	FILE *fp = fopen(argv[1], "rw");
	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		exit(-1);
	}

	ret = getline(&buf, &n, fp);
	if (ret == -1) {
		fprintf(stderr, "getline error\n");
		exit(-1);
	}

	processBuf(buf, n);
	printf("\n");
	return 0;
}
