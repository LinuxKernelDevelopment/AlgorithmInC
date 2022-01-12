#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

char *infixToPostfix(char *a)
{
	int i, N = strlen(a);
	Stack *operand = STACKinit(N);
	Stack *operator  = STACKinit(N);
	char *op, *exp;
	char *operand1;
	char *operand2;
	for (i = 0; i < N; i++) {
		switch (a[i]) {
		case '(':
			break;
		case '+':
		case '*':
		case '/':
		case 's':
			op = calloc(2, 1);
			op[0] = a[i];
			STACKpush(operator, op);
			break;

		case '-':
			if (a[i-1] == '(') {
				op = calloc(2, 1);
				op[0] = '_';
				STACKpush(operator, op);
			} else {
				op = calloc(2, 1);
				op[0] = a[i];
				STACKpush(operator, op);
			}
			break;

		case ')':
			op = STACKpop(operator);
			if (op[0] != '_' && op[0] != 's') {
				operand2 = STACKpop(operand);
				operand1 = STACKpop(operand);
				exp = calloc(strlen(operand1) + strlen(operand2) + 4, 1);
				sprintf(exp, "%s %s %c", operand1, operand2, op[0]);
				STACKpush(operand, exp);
			} else {
				operand1 = STACKpop(operand);
				exp = calloc(strlen(operand1) + 2, 1);
				sprintf(exp, "%s %c", operand1, op[0]);
				STACKpush(operand, exp);
			}
			break;

		default:
			if (a[i] >= 65 && a[i] <= 122) {
				int j = i;
				while (a[j] >= 65 && a[j] <= 122)
					j++;
				char *key = calloc(j - i + 2, 1);
				memcpy(key, &a[i], j - i);
				STACKpush(operand, key);
			}

			if (a[i] >= 48 && a[i] <= 57) {
				int j = i;
				while (a[j] >= 48 && a[j] <= 57)
					j++;
				char *key = calloc(j - i + 2, 1);
				memcpy(key, &a[i], j - i);
				STACKpush(operand, key);
			}
			break;
		}
	}
	char *output = STACKpop(operand);
	return output;
}

double evalPost(char *a)
{
	int N = strlen(a);
	Stack *evalStack = STACKinit(N);
	char *operand1, *operand2, *buf;
	double val1, val2;
	for (int i = 0; i < N; i++) {
		switch (a[i]) {
		case '+':
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);

			val1 = atof(operand1);
			val2 = atof(operand2);

			buf = calloc(50, 1);
			sprintf(buf, "%lf", (double)val1 + (double)val2);
			STACKpush(evalStack, buf);
			break;

		case '-':
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);

			val1 = atof(operand1);
			val2 = atof(operand2);

			buf = calloc(50, 1);
			sprintf(buf, "%lf", (double)val1 - (double)val2);
			STACKpush(evalStack, buf);
			break;

		case '*':
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);

			val1 = atof(operand1);
			val2 = atof(operand2);

			buf = calloc(50, 1);
			sprintf(buf, "%lf", (double)val1 * (double)val2);
			STACKpush(evalStack, buf);
			break;

		case '/':
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);

			val1 = atof(operand1);
			val2 = atof(operand2);

			buf = calloc(50, 1);
			sprintf(buf, "%lf", (double)val1 / (double)val2);
			STACKpush(evalStack, buf);
			break;

		case 's':
			operand1 = STACKpop(evalStack);

			val1 = atof(operand1);
			buf = calloc(50, 1);
			sprintf(buf, "%lf", sqrt(val1));
			STACKpush(evalStack, buf);
			break;
	
		case '_':
			operand1 = STACKpop(evalStack);

			val1 = atof(operand1);
			buf = calloc(50, 1);
			sprintf(buf, "%lf", -val1);
			STACKpush(evalStack, buf);
			break;

		default:
			if ((a[i] >= '0') && (a[i] <= '9')) {
				int j = i;
				while (a[j] >= '0' && a[j] <= '9' || a[j] == '.')
					j += 1;
				char *num = calloc(j-i+1, 1);
				memcpy(num, &a[i], j - i);
				STACKpush(evalStack, num);	
			}
		}
	}

	buf = STACKpop(evalStack);
	return atof(buf);
}

int main(int argc, char *argv[])
{
	char *out = infixToPostfix(argv[1]);
	printf("%s\n", out);
	printf("%lf\n", evalPost(out));
	return 0;
}
