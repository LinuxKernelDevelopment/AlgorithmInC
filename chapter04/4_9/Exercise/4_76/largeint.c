#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "largeint.h"

typedef struct largeInt *LI;
struct largeInt {
	int negative;
	int bitNum;
	unsigned char *bigInt;
};

int isLIone(LI li)
{
	if (li->negative == 0 && strcmp(li->bigInt, "1") == 0)
		return 1;
	return 0;
}

LI LIinit(char *num)
{
	char *dataptr;
	int i;
	LI new;

	new = malloc(sizeof *new);
	for (i = 0; i < strlen(num); i++) {
		if (num[i] >= '1' && num[i] <= '9' || num[i] == '-')
			break;
	}
	if (num[i] == '-') {
		new->negative = 1;
		dataptr = &num[i] + 1;
	} else {
		new->negative = 0;
		dataptr = &num[i];
	}

	if (*num == '0' && strlen(num) == 1) {
		new = malloc(sizeof *new);
		new->bitNum = 1;
		new->bigInt = malloc(sizeof(char) * 2);
		new->bigInt[1] = 0;
		new->bigInt[0] = '0';
		new->negative = 0;
		return new;
	}
	if (num[i] == '-')
		new->bitNum = strlen(num) - i - 1;
	else
		new->bitNum = strlen(num) - i;
	new->bigInt = malloc(sizeof(char) * (new->bitNum + 1));
	memset(new->bigInt, 0, new->bitNum + 1);
	memcpy(new->bigInt, dataptr, new->bitNum);

	return new;
}

void LIdestroy(LI d)
{
	free(d->bigInt);
	free(d);
}

static int LIabsGreater(LI left, LI right)
{
	char *lp, *rp;
	if (left->bitNum > right->bitNum)
		return 1;
	else if (left->bitNum < right->bitNum)
		return -1;
	else {
		for (lp = left->bigInt, rp = right->bigInt;
				*lp != '\0' && *rp != '\0';
				lp++, rp++) {
			if (*lp > *rp)
				return 1;
			else if (*lp < *rp)
				return -1;
		}
		return 0;
	}
}

int LIgreater(LI left, LI right)
{
	if (left->negative == 1 && right->negative == 0)
		return -1;
	if (left->negative == 0 && right->negative == 1)
		return 1;
	if (left->negative == 1 && right->negative == 1) {
		switch (LIabsGreater(left, right)) {
		case 1:
			return -1;
		case -1:
			return 1;
		case 0:
			return 0;
		}
	}
	if (left->negative == 0 && right->negative == 0) {
		switch(LIabsGreater(left, right)) {
		case 1:
			return 1;
		case -1:
			return -1;
		case 0:
			return 0;
		}
	}
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
	LI new, LItmp;
	char *tmp, *cpy;
	int leftLen = left->bitNum;
	int rightLen = right->bitNum;
	int tmpLen, curPos, negative;
	char r = 0, carry = 0;

	if (left->negative == 1 && right->negative == 1)
		negative = 1;
	else if (left->negative == 0 && right->negative == 0)
		negative = 0;
	else if (left->negative == 0 && right->negative == 1) {
		LItmp = LIinit(right->bigInt);
		LItmp->negative = 0;
		new = LIsub(left, LItmp);
		return new;
	} else if (left->negative == 1 && right->negative == 0) {
		LItmp = LIinit(left->bigInt);
		LItmp->negative = 0;
		new = LIsub(right, LItmp);
		return new;
	}

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
	if (negative)
		new->negative = 1;
	else
		new->negative = 0;
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

static void switchPointer(LI *left, LI *right)
{
	LI tmp;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

LI LIsub(LI left, LI right)
{
	LI new, LItmp, leftTmp, rightTmp;
	int negative;
	unsigned char *leftp, *rightp;
	int leftLen, rightLen;
	int tmpLen, curPos;
	char *tmp, r, *save;

	if (left->negative == 0 && right->negative == 1) {
		LItmp = LIinit(right->bigInt);
		LItmp->negative = 0;
		new = LIadd(left, LItmp);
		LIdestroy(LItmp);
		return new;
	} else if (left->negative == 1 && right->negative == 0) {
		leftTmp = LIinit(left->bigInt);
		rightTmp = LIinit(right->bigInt);
		leftTmp->negative = rightTmp->negative = 0;
		new = LIadd(leftTmp, rightTmp);
		new->negative = 1;
		LIdestroy(leftTmp);
		LIdestroy(rightTmp);
		return new;
	} else if (left->negative == 0 && right->negative == 0) {
		if (LIgreater(left, right) == 1)
			negative = 0;
		else {
			negative = 1;
			switchPointer(&left, &right);
		}
	} else {
		rightTmp = LIinit(right->bigInt);
		rightTmp->negative = 0;
		leftTmp = LIinit(left->bigInt);
		leftTmp->negative = 0;
		new = LIsub(rightTmp, leftTmp);
		LIdestroy(leftTmp);
		LIdestroy(rightTmp);
		return new;
	}

	leftLen = left->bitNum, rightLen = right->bitNum;
	tmpLen = leftLen > rightLen ? leftLen + 1 : rightLen + 1;
	tmp = malloc(tmpLen + 1);
	memset(tmp, '0', tmpLen + 1);
	tmp[tmpLen] = 0;

	save = malloc(leftLen + 1);
	memset(save, 0, leftLen + 1);
	memcpy(save, left->bigInt, leftLen);

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
	if (negative)
		new->negative = 1;
	else
		new->negative = 0;
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
	int negative = left->negative ^ right->negative;

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
	sum->negative = negative;
	return sum;
}

static int LInegative(LI num)
{
	int ret;
	LI zero = LIinit("0");

	ret = LIgreater(zero, num);

	return ret == 1;
}

/*static LI computeQuot(LI left, LI right)
{
	int i, len;
	char *quotStr;
	LI quot, mulRet, leftTmp;

	len = left->bitNum - right->bitNum + 1;
	quotStr = malloc(sizeof(char) * (len));
	quotStr[len - 1] = '\0';
	for (int j = len - 2; j != 0; j--)
		quotStr[j] = '0';
	for (i = 1; i < 10; i++) {
		quotStr[0] = '0' + i;
		quot = LIinit(quotStr);
		mulRet = LImult(quot, right);
		leftTmp = LIsub(left, mulRet);
		if (LInegative(leftTmp))
			break;
		LIdestroy(quot);
		LIdestroy(leftTmp);
	}
	i -= 1;
	quotStr[0] = '0' + i;
	quot = LIinit(quotStr);
	free(quotStr);
	return quot;
}*/

static LI computeQuot(LI left, LI right)
{
	char *diviStr, *quotStr, *tmpStr;
	LI divi, quot, mulRet, leftTmp;
	int quotLen, i;
	int diviLen = left->bitNum;

	diviStr = malloc(sizeof(char) * (diviLen + 1));
	memset(diviStr, '0', diviLen);
	diviStr[diviLen] = '\0';

	for (int i = 0; i < right->bitNum; i++) {
		diviStr[i] = right->bigInt[i];
	}
	divi = LIinit(diviStr);
	if (LIgreater(divi, left) == 1) {
		diviStr[diviLen - 1] = '\0';
		LIdestroy(divi);
		divi = LIinit(diviStr);
	}

	tmpStr = malloc(sizeof(char) * left->bitNum);
	for (i = 0; i < 10; i++) {
		sprintf(tmpStr, "%d", i);
		LI tmp = LIinit(tmpStr);
		mulRet = LImult(tmp, divi);
		leftTmp = LIsub(left, mulRet);
		if (LInegative(leftTmp))
			break;
	}
	i -= 1;
	quotLen = divi->bitNum - right->bitNum + 2;
	quotStr = malloc(sizeof(char) * quotLen);
	memset(quotStr, '0', quotLen);
	quotStr[quotLen - 1] = '\0';
	quotStr[0] = i + '0';
	quot = LIinit(quotStr);
	return quot;
}

static LI LIabs(LI num)
{
	LI new;

	new = LIinit(num->bigInt);
	new->negative = 0;

	return new;
}

void LIdiv(LI left, LI right, LI *result, LI *remain)
{
	int negative;
	LI quotient;
	LI leftTmp, rightTmp, loopTmp, mulRet;
	LI *tmp;
	int idx = 0;
	LI sum = LIinit("0");

	negative = left->negative ^ right->negative;
	leftTmp = LIabs(left);
	rightTmp = LIabs(right);

	if (LIgreater(rightTmp, leftTmp) == 1) {
		*result = LIinit("0");
		*remain = LIsub(leftTmp, *result);
		return;
	}

	tmp = malloc(sizeof(LI) * (leftTmp->bitNum - rightTmp->bitNum));
	while (LIgreater(leftTmp, rightTmp) == 1) {
		quotient = computeQuot(leftTmp, rightTmp);
		mulRet = LImult(rightTmp, quotient);
		loopTmp = LIsub(leftTmp, mulRet);
		tmp[idx++] = quotient;
		LIdestroy(mulRet);
		LIdestroy(leftTmp);
		leftTmp = loopTmp;
	}

	for (int i = 0; i < idx; i++) {
		sum = LIadd(sum, tmp[i]);
	}

	sum->negative = negative;
	if (negative) {
		LI tmp = LIinit("1");
		LI nc = LIsub(sum, tmp);
		LIdestroy(tmp);
		LIdestroy(sum);
		sum = nc;
	}
	*result = sum;
	mulRet = LImult(sum, right);
	*remain = LIsub(left, mulRet);
}

void printLI(LI li)
{
	if (li->negative)
		printf("-%s", li->bigInt);
	else
		printf("%s", li->bigInt);
}
