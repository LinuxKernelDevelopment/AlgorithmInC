#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct largeInt *LI;
struct largeInt {
	int bitNum;
	unsigned char *bigInt;
};

LI LIinit(char *num)
{
	int i;
	LI new;

	for (i = 0; i < strlen(num); i++) {
		if (num[i] >= '1' && num[i] <= '9')
			break;
	}
	if (*num == '0' && strlen(num) == 1) {
		new = malloc(sizeof *new);
		new->bitNum = 1;
		new->bigInt = malloc(sizeof(char) * 2);
		new->bigInt[1] = 0;
		new->bigInt[0] = '0';
		return new;
	}
	new = malloc(sizeof *new);
	new->bitNum = strlen(num) - i;
	new->bigInt = malloc(sizeof(char) * new->bitNum);
	strncpy(new->bigInt, &num[i], new->bitNum);

	return new;
}

void LIdestroy(LI d)
{
	free(d->bigInt);
	free(d);
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
	char *tmp, *cpy;
	int leftLen = left->bitNum;
	int rightLen = right->bitNum;
	int tmpLen, curPos;
	char r, carry = 0;

	tmpLen = leftLen > rightLen ? leftLen + 1 : rightLen + 1; // '\0'
	tmp = malloc(tmpLen + 1);  // carry bit
	memset(tmp, '0', tmpLen + 1);
	tmp[tmpLen] = 0;
	for (leftp = &left->bigInt[leftLen - 1], rightp = &right->bigInt[rightLen - 1], curPos = tmpLen - 1;
			leftp != left->bigInt - 1 && rightp != right->bigInt - 1;
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

	for (; longp != endp; longp--, curPos--) {
		addNum(*longp, '0', &r, &carry);
		tmp[curPos] = r + '0';
	}

	if (carry) {
		tmp[curPos] = carry + '0';
		carry = 0;
	}

	if (curPos != 0) {
		cpy = tmp + 1;
		tmpLen -= 1;
	}

	new = LIinit(tmp);
	/*new = malloc(sizeof *new);
	new->bitNum = tmpLen;
	new->bigInt = malloc(sizeof(char) * tmpLen);
	memcpy(new->bigInt, cpy, tmpLen + 1);*/
	free(tmp);

	return new;
}

static void subNum(LI LIleft, char *left, char *right, char *r)
{
	int leftNum = *left - '0';
	int rightNum = *right - '0';
	char *bp, *bpp;

	if (leftNum >= rightNum) {
		*r = leftNum - rightNum;
	} else {
		assert(LIleft->bigInt - 1 < (unsigned char *) left);
		bp = left - 1;
		if (*bp > '0') {
			*bp = *bp - 1;
			leftNum = leftNum + 10;
			*r = leftNum - rightNum;
		} else {
			bpp = bp - 1;
			while (*bpp == '0') {
				*bp = '9';
				bp--;
				bpp--;
			}
			*bp = '9';
			*bpp -= 1;
			leftNum = leftNum + 10;
			*r = leftNum - rightNum;
		}
	}
}

LI LIsub(LI left, LI right)
{
	LI new;
	unsigned char *leftp, *rightp;
	int leftLen = left->bitNum;
	int rightLen = right->bitNum;
	int tmpLen, curPos;
	char *tmp, r, *save;
	save = malloc(leftLen + 1);
	memset(save, 0, leftLen + 1);
	memcpy(save, left->bigInt, leftLen);

	tmpLen = leftLen > rightLen ? leftLen + 1 : rightLen + 1;
	tmp = malloc(tmpLen + 1);
	memset(tmp, '0', tmpLen + 1);
	tmp[tmpLen] = 0;
	for (leftp = &left->bigInt[leftLen - 1], rightp = &right->bigInt[rightLen - 1], curPos = tmpLen - 1;
			leftp != left->bigInt - 1 && rightp != right->bigInt - 1;
			leftp--, rightp--, curPos--) {
		subNum(left, leftp, rightp, &r);
		tmp[curPos] = r + '0';
	}

	for (; leftp != left->bigInt - 1; leftp--, curPos--) {
		tmp[curPos] = *leftp;
	}

	new = LIinit(tmp);
	free(tmp);
	free(left->bigInt);
	left->bigInt = save;

	return new;
}

static void multNum(char left, char right, char *r, char *carry)
{
	int result;
	int leftNum = left - '0';
	int rightNum = right - '0';

	result = leftNum * rightNum + *carry;

	*carry = result / 10;
	*r = result % 10;
}

static LI multSingle(LI left, char factor, int curPos)
{
	unsigned char *leftp;
	char *tmp;
	LI new;
	char r = 0, carry = 0;
	int leftLen = left->bitNum + curPos;

	tmp = malloc(sizeof(char) * (leftLen + 2)); // '\0' & carray bit
	memset(tmp, '0', leftLen + 2);
	tmp[leftLen + 1] = 0;
	for (int i = 0; i < curPos; i++) {
		tmp[leftLen - i] = '0';
	}
	for (leftp = &left->bigInt[left->bitNum - 1]; leftp != left->bigInt - 1; leftp--) {
		multNum(*leftp, factor, &r, &carry);
		curPos += 1;
		tmp[leftLen - curPos + 1] = r + '0';
	}
	if (carry) {
		curPos += 1;
		tmp[leftLen - curPos + 1] = carry + '0';
	}
	new = LIinit(tmp);
	return new;
}

LI LImult(LI left, LI right)
{
	unsigned char *leftp, *rightp;
	LI *tmp;
	LI sum = LIinit("0");

	int leftLen = left->bitNum;
	int rightLen = right->bitNum;
	int curPos;

	tmp = malloc(sizeof(LI) * rightLen);
	curPos = 0;
	int i = 0;
	for (rightp = &right->bigInt[rightLen - 1]; rightp != right->bigInt - 1; rightp--) {
		tmp[i++] = multSingle(left, *rightp, curPos++);
	}

	for (int i = 0; i < rightLen; i++) {
		sum = LIadd(sum, tmp[i]);
	}
	return sum;
}

void printLI(LI li)
{
	printf("%s", li->bigInt);
}
