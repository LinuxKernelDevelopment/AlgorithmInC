#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "largeint.h"
#include "Item.h"
#include "STACK.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
	char *tmp;
	size_t n, ret;
	int i, idx = 0;
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen failed");
		exit(-1);
	}

	ret = getline(&line, &n, fp);
	
	tmp = malloc(sizeof(char) * n);

	for (i = 0; line[i] != '\n'; i++);
	line[i] = '\0';
	n = i;

	STACKinit(n);
	for (i = 0; i < n; i++)
	{
		if (line[i] == ' ')
			continue;
		if (line[i] == '+') {
			STACKpush(LIadd(STACKpop(), STACKpop()));
			continue;
		}
		if (line[i] == '*') {
			STACKpush(LImult(STACKpop(), STACKpop()));
			continue;
		}
		if (line[i] == '-') {
			LI right = STACKpop();
			LI left = STACKpop();
			STACKpush(LIsub(left, right));
			continue;
		}
		if (line[i] == '/') {
			LI right = STACKpop();
			LI left = STACKpop();
			LI result, remain;

			LIdiv(left, right, &result, &remain);
			STACKpush(result);
			continue;
		}
		if (line[i] == '%') {
			LI right = STACKpop();
			LI left = STACKpop();
			LI result, remain;

			LIdiv(left, right, &result, &remain);
			STACKpush(remain);
			continue;
		}
		//if ((a[i] >= '0') && (a[i] <= '9'))
			//STACKpush(0);
		while ((line[i] >= '0') && (line[i] <= '9')) {
			tmp[idx++] = line[i++];
		}
		tmp[idx] = '\0';
		idx = 0;
		STACKpush(LIinit(tmp));
	}
	printLI(STACKpop());
	printf("\n");
}
