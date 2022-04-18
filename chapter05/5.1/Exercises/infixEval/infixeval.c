#include <stdio.h>
#include <assert.h>

static int isNum(char c)
{
	return c >= '0' && c <= '9';
}

static int isOp(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int infixEval(char **str)
{
	int num = 0, num1, num2, val;
	char *t = *str;
	char op;

	assert(*t == '(');
	t += 1;
		
	while (*t == ' ')
		t += 1;

	if (isNum(*t)) {
		while (isNum(*t)) {
			num = num * 10 + (*t - '0');
			t += 1;
		}
		assert(*t == ')');
		*str = t;
		return num;
	}

	if (*t == '(')
		num1 = infixEval(&t);
	assert(*t == ')');
	t += 1;

	if (*t == '\0') {
		*str = t;
		return num1;
	}

	while (*t == ' ')
		t += 1;

	assert(isOp(*t));
	op = *t++;

	while (*t == ' ')
		t += 1;

	if (*t == '(')
		num2 = infixEval(&t);
	assert(*t == ')');
	t += 1;

	switch (op) {
	case '+':
		val = num1 + num2;
		break;
	case '-':
		val = num1 - num2;
		break;
	case '/':
		val = num1 / num2;
		break;
	case '*':
		val = num1 * num2;
		break;
	}

	*str = t;
	return val;
}

int main(int argc, char *argv[])
{
	char *str = "(((1) + (((2) * (3)) + (5))) + (1872))";
	printf("%d\n", infixEval(&str));
	return 0;
}
