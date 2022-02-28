#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct largeInt *LI;
struct largeInt {
	int bitNum;
	unsigned char *bigInt;
};

LI LIinit(char *num)
{
	LI new;

	new = malloc(sizeof *new);
	new->bitNum = strlen(num);
	new->bigInt = malloc(sizeof(char) * new->bitNum);
	strncpy(new->bigInt, num, new->bitNum);

	return new;
}

static void addNum(char left, char right, char *r, char *carry)
{
	int result;
	int leftNum = left - '0';
	int rightNum = right - '0';

	result = leftNum + rightNum + *carry;
	if (result >= 10) {
		*carry = 1;
		*r = result - 10;
	} else {
		*carry = 0;
		*r = result;
	}
}

LI LIadd(LI left, LI right)
{
	unsigned char *leftp, *rightp, *longp, *endp;
	LI new;
	char *tmp;
	int leftLen = left->bitNum;
	int rightLen = right->bitNum;
	int tmpLen, curPos;
	char r, carry = 0;

	tmpLen = leftLen > rightLen ? leftLen + 1 : rightLen + 1; // '\0'
	tmp = malloc(tmpLen + 1);  // carry bit
	for (leftp = &left->bigInt[leftLen - 1], rightp = &right->bigInt[rightLen - 1], curPos = tmpLen - 1;
			leftp != left->bigInt - 1&& rightp != right->bigInt - 1;
			leftp--, rightp--, curPos--) {
		addNum(*leftp, *rightp, &r, &carry);
		tmp[curPos] = r + '0';
	}

	if (leftp == left->bigInt - 1) {
		longp = rightp;
		endp = right->bigInt - 1;
	} else {
		longp = leftp;
		endp = left->bigInt - 1;
	}

	for (; longp != endp - 1; longp--, curPos--) {
		addNum(*longp, '0', &r, &carry);
		tmp[curPos] = r + '0';
	}

	if (curPos != 0) {
		tmp = tmp + 1;
		tmpLen -= 1;
	}

	new = malloc(sizeof *new);
	new->bitNum = tmpLen;
	new->bigInt = tmp;

	return new;
}

void printLI(LI li)
{
	printf("%s", li->bigInt);
}
