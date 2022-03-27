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

static int isOp(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

static int isNum(char c)
{
	return c >= '0' && c <= '9';
}

char *infixToPost(char **str)
{
	char *t = *str;
	char *operand1, *operand2, *out;
	int num = 0, bitNum = 0, slen = 0, op;

	assert(*t == '(');
	t += 1;

	if (isNum(*t)) {
		while (isNum(*t)) {
			bitNum += 1;
			num += num * 10 + (*t - '0');
			t += 1;
		}
		slen = bitNum + 1;
		out = malloc(slen);
		out[slen - 1] = '\0';
		sprintf(out, "%d", num);
		*str = t;
		return out;
	}

	if (*t == '(') {
		operand1 =  infixToPost(&t);
		assert(*t == ')');
		t += 1;
		skipSpace(&t);
	}

	skipSpace(&t);

	assert(isOp(*t));
	op = *t;
	t += 1;

	skipSpace(&t);

	assert(*t == '(');
	if (*t == '(') {
		operand2 = infixToPost(&t);
		assert(*t == ')');
		t += 1;
		skipSpace(&t);
	}

	slen = strlen(operand1) + strlen(operand2) + 4;
	out = malloc(slen);
	out[slen - 1] = '\0';
	sprintf(out, "%s %s %c", operand1, operand2, op);
	free(operand1);
	free(operand2);
	*str = t;
	return out;
}

int main(int argc, char *argv[])
{
	char *str = "((5) * (((9) * (8)) + ((7) * ((4) + (6)))))";
	printf("%s\n", infixToPost(&str));
	return 0;
}
