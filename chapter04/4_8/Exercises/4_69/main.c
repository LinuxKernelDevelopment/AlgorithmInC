#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "COMPLEX.h"
#include "Item.h"
#include "STACK.h"

int isAddSub(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

int parseNum(char *buf, int beg, int end)
{
	int num = 0;
	for (int i = beg; i <= end; i++) {
		num = num * 10 + (buf[i] - '0');
	}
	return num;
}

Complex parseComplex(char *buf)
{
	int i, ep, ImBeg, ReEnd;
	float im, re;

	for (i = 0; buf[i] != 'i'; i++);
	ep = i;
	for (i = 0; !isAddSub(buf[i]); i++);
	ReEnd = i - 1;
	ImBeg = i + 1;
	
	re = parseNum(buf, 0, ReEnd);
	im = parseNum(buf, ImBeg, ep-1);

	if (buf[i] == '-')
		im = -im;

	return COMPLEXinit(re, im);
}

Complex evalPostfixComplex(char *buf)
{
	int i = 0, j = 0;
	STACK s = STACKinit(100);
	Complex c;
	for (i = 0; buf[i] != '\0'; i++) {
		if (buf[i] >= '0' && buf[i] <= '9') {
			c = parseComplex(&buf[i]);
			STACKpush(s, c);
			for (j = i; buf[j] != ' '; j++);
			i = j;
		}
		if (buf[i] == '+') {
			c = COMPLEXadd(STACKpop(s), STACKpop(s));
			STACKpush(s, c);
		}
		if (buf[i] == '*') {
			c = COMPLEXmult(STACKpop(s), STACKpop(s));
			STACKpush(s, c);
		}
	}
	c = STACKpop(s);
	printf("Re:%f, Im:%f\n", Re(c), Im(c));
	return c;
}

int main(int argc, char *argv[])
{
	char *line = NULL, *buf = NULL;
	size_t n;
	Complex c;
	int i;
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen failed");
		exit(-1);
	}
	while (getline(&line, &n, fp) != -1) {
		for (i = 0; line[i] != '\n'; i++);
		line[i] = 0;
		evalPostfixComplex(line);
		//c = parseComplex(line);
		//printf("Re:%f, Im:%f\n", c.Re, c.Im);

	}
	return 0;
}
