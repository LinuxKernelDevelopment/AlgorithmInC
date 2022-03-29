#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

static void skipSpace(char **str)
{
	char *t = *str;

	while (*t == ' ')
		t += 1;

	*str = t;
}

static void skipSpaceBackword(char **str)
{
	char *b = *str;

	while (*b == ' ')
		b -= 1;

	*str = b;
}

static int isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

static int isNum(char c)
{
	return c >= '0' && c <= '9';
}

static int allNum(char *p, char *q)
{
	while (isNum(*p)) {
		if (p == q)
			return 1;
		p += 1;
	}
	return 0;
}


/*char *postfixToInfix(char **str)
{
	char *t = *str;
	char *operand1, *operand2, *out;
	int num = 0, bitNum = 0, slen = 0, op;

	if (isNum(*t)) {
		while (isNum(*t)) {
			bitNum += 1;
			num += num * 10 + (*t - '0');
			t += 1;
		}
		slen = bitNum + 3;
		out = malloc(slen);
		out[slen - 1] = '\0';
		sprintf(out, "(%d)", num);
		*str = t;
		return out;
	}

	operand1 = postfixToInfix(&t);

	skipSpace(&t);

	operand2 = postfixToInfix(&t);

	skipSpace(&t);

	op = *t;

	slen = strlen(operand1) + strlen(operand2) + 6;
	out = malloc(slen);
	out[slen - 1] = '\0';
	sprintf(out, "(%s %c %s)", operand1, op, operand2);
	free(operand1);
	free(operand2);
	*str = t;
	return out;
}*/

/*static int countTailOp(char *str, char *b)
{
	char *tmp;
	int nr = 0;
	for (tmp = b; tmp != str && !isNum(*tmp); tmp--);
	assert (tmp != str);

	for (; tmp != b; tmp++) {
		if (isOp(*tmp))
			nr += 1;
	}

	return nr;
}*/

char *postfixToInfix2(char *str)
{
	char *t = str;
	char *b, *subStr, *operand1, *operand2, *out; 
	int slen = 0, num = 0, bitNum = 0, op, strLen = 0, subStrLen;
	int tailOp;

	skipSpace(&t);
	assert(isNum(*t));

	while (isNum(*t)) {
		bitNum += 1;
		num += num * 10 + (*t - '0');
		t += 1;
	}

	slen = bitNum + 3;
	operand1 = malloc(slen);
	operand1[slen - 1] = '\0';
	sprintf(operand1, "(%d)", num);
	skipSpace(&t);

	strLen = strlen(t);
	b = &t[strLen - 1];
	skipSpaceBackword(&b);
	assert(isOp(*b));

	op = *b;
	b -= 1;
	skipSpaceBackword(&b);


	if (allNum(t, b)) {
		slen = b - t + 1;
		/*while (isNum(*t)) {
			bitNum += 1;
			num += num * 10 + (*t - '0');
			t += 1;
		}*/

		operand2 = malloc(sizeof(char) * (slen + 3));
		operand2[slen + 2] = '\0';
		operand2[0] = '(';
		operand2[slen + 1] = ')';
		memcpy(operand2 + 1, t, slen);

		slen = strlen(operand1) + strlen(operand2) + 6;
		out = malloc(slen);
		out[slen - 1] = '\0';
		sprintf(out, "(%s %c %s)", operand1, op, operand2);
		free(operand1);
		free(operand2);
		return out;
	}

	subStrLen = b - t + 1;
	subStr = malloc(subStrLen + 1);
	subStr[subStrLen] = '\0';
	memcpy(subStr, t, subStrLen);

	operand2 = postfixToInfix2(subStr);

	slen = strlen(operand1) + strlen(operand2) + 6;
	out = malloc(slen);
	out[slen - 1] = '\0';
	sprintf(out, "(%s %c %s)", operand1, op, operand2);
	free(operand1);
	free(operand2);
	
	return out;
}

/*static int countTailOp(char *str, char *b)
{
	char *tmp;
	int nr = 0;
	for (tmp = b; tmp != str && !isNum(*tmp); tmp--) {
		if (isOp(*tmp))
			nr += 1;
	}
	return nr;
}*/

char *subStrStart(char *t)
{
	assert(isNum(*t));
	while (isNum(*t)) t++;
	assert(*t == ' ');
	t += 1;
	assert(isNum(*t));
	return t;
}

static int getNum(char **str)
{
	int num = 0;
	char *t = *str;
	while (isNum(*t)){
		num = 10 * num + (*t - '0');
		t += 1;
	}
	*str = t;
	return num;
}

static int countStartNum(char *t)
{
	int num = 0;
	skipSpace(&t);
	assert(isNum(*t));
	while (!isOp(*t)) {
		getNum(&t);
		skipSpace(&t);
		num += 1;
	}
	return num;
}

static int countOpNum(char *t, char *b)
{
	int nrOp = 0;

	while (!isOp(*t))
		t += 1;

	assert(isOp(*t));

	while ((isOp(*t) || *t == ' ') && t != b + 1) {
		if (isOp(*t))
			nrOp += 1;
		t += 1;
	}
	return nrOp;
}

static char *getEndOfFstSub(char *t)
{
	while (!isOp(*t))
		t += 1;
	assert(isOp(*t));

	while (!isNum(*t) && *t != '\0')
		t += 1;
	t -= 1;
	return t;
}

static char *skipNum(char *t)
{
	while (isNum(*t))
		t += 1;
	return t;
}

char *postfixToInfix(char *str)
{
	char *t, *b, *subStr, *subStr2;
	char *operand1, *operand2, *out;
	int slen;
	int nrOp, nrStart;
	int op, subLen, opLen, subLen2, outLen;
	int num1, num2;

	slen = strlen(str);

	t = skipNum(str);
	assert(*t == ' ');
	skipSpace(&t);
	
	b = &str[slen - 1];
	assert(isOp(*b));
	op = *b;
	b -= 1;
	skipSpaceBackword(&b);

	nrStart = countStartNum(str);
	printf("nrStart:%d\n", nrStart);

	nrOp = countOpNum(str, b);
	printf("nrOp:%d\n", nrOp);


	if (allNum(t, b)) {
		t = str;

		num1 = getNum(&t);
		skipSpace(&t);
		num2 = getNum(&t);
		
		slen = t - str - 1 + 9;

		out = malloc(sizeof(char) * (slen + 1));
		out[slen] = '\0';
		sprintf(out, "((%d) %c (%d))", num1, op, num2);
		return out;

	}

	if (nrStart == nrOp + 1) {
		/*
		 9 8 * 7 4 6 + * + 
		 */

		t = str;
		char *fstSubEnd = getEndOfFstSub(t);
		subLen = fstSubEnd - t;
		subStr = malloc(sizeof(char) * (subLen + 1));
		subStr[subLen] = '\0';
		memcpy(subStr, str, subLen);
		printf("subStr:%s\n", subStr);
		operand1 = postfixToInfix(subStr);
		
		t = fstSubEnd + 1;
		skipSpace(&t);
		subLen2 = b - t + 1;

		subStr2 = malloc(sizeof(char) * (subLen2 + 1));
		subStr2[subLen2] = '\0';
		memcpy(subStr2, t, subLen2);
		operand2 = postfixToInfix(subStr2);

		outLen = strlen(operand1) + strlen(operand2) + 5;
		out = malloc(sizeof(char) * (outLen + 1));
		out[outLen] = '\0';
		sprintf(out, "(%s %c %s)", operand1, op, operand2);
		printf("subStr2:%s\n", subStr2);
		free(subStr);
		free(subStr2);
		return out;
	} else { 
		/*
		 5 9 8 * 7 4 6 + * + *
		 */
		t = str;
		num1 = getNum(&t);
		assert(*t == ' ');
		
		opLen = t - str;
		operand1 = malloc(sizeof(char) * (opLen + 3));
		operand1[opLen] = '\0';
		sprintf(operand1, "(%d)", num1);

		skipSpace(&t);
		subLen2 = b - t + 1;

		subStr2 = malloc(sizeof(char) * (subLen2 + 1));
		subStr2[subLen2] = '\0';
		memcpy(subStr2, t, subLen2);

		operand2 = postfixToInfix(subStr2);
		outLen = strlen(operand1) + strlen(operand2) + 9;
		out = malloc(sizeof(char) * (outLen + 1));
		sprintf(out, "(%s %c %s)", operand1, op, operand2);
		free(subStr2);
		free(operand1);
		free(operand2);
		return out;

	}

	t = subStrStart(str);


	subLen = slen - 4;
	subStr = malloc(sizeof(char) * subLen);
	subStr[subLen - 1] = '\0';
	memcpy(subStr, t, subLen);
	printf("subStr:%s\n", subStr);

	return NULL;
}

int main(int argc, char *argv[])
{
	char *str = "5 9 8 * 7 4 6 + * + *";
	char *str2 = "4 6 +";
	printf("%s\n", postfixToInfix(str));
	return 0;
}
