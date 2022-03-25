#include <stdio.h>

static int IsNum(char c)
{
	return c >= '0' && c <= '9';
}

static int IsOp(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int postfixExpr(char **evalStr)
{
	int i;
	int num1 = 0, num2 = 0, val;
	char *t = *evalStr;

	while (*t == ' ')
		t += 1;

	while (IsNum(*t)) {
		num1 = num1 * 10 + (*t - '0');
		t += 1;
	}

	while (*t == ' ')
		t += 1;

	if (IsOp(*t)) {
		*evalStr = t;
		return num1;
	}

	num2 = postfixExpr(&t);

	while (*t == ' ')
		t += 1;

	switch (*t++) {
	case '+':
		val = num1 + num2;
		break;
	case '-':
		val = num1 - num2;
		break;
	case '*':
		val = num1 * num2;
		break;
	case '/':
		val = num1 / num2;
		break;
	}
	
	*evalStr = t;
	return val;
}

int postfixEval(char **evalStr)
{
	int num, val;
	char *t = *evalStr;

	val = postfixExpr(&t);

	while (*t == ' ')
		t += 1;

	while (*t) {
		num = postfixExpr(&t);
		
		while (*t == ' ')
			t += 1;

		switch (*t++) {
		case '+':
			val = val + num;
			break;
		case '-':
			val = val - num;
			break;
		case '*':
			val = val * num;
			break;
		case '/':
			val = val / num;
			break;
		}
	}
	return val;
}

int main(int argc, char *argv[])
{
	char *str = "1 2 671 * + 1 + 2 5 * +";
	printf("%d\n", postfixEval(&str));
	return 0;
}
