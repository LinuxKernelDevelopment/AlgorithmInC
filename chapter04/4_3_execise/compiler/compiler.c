#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "STACK.h"
#include "compiler.h"

stEntry *sTable;
int numId = 0;

void initSymbolTable(void)
{
	sTable = malloc(sizeof(stEntry) * 100);
	if (!sTable) {
		fprintf(stderr, "malloc failed");
		exit(-1);
	}
}

int getIndexFromStable(char *id)
{
	int i;
	for (i = 0; i < numId; i++) {
		if (strcmp(sTable[i].symbol, id) == 0)
			return i;
	}
	return -1;
}

int getValFromStable(char *id)
{
	int idx = getIndexFromStable(id);
	if (idx != -1)
		return sTable[idx].val;
}

int setValToStable(char *id, int val)
{
	int idx = getIndexFromStable(id);
	if (idx != -1) {
		sTable[idx].val = val;
	} else {
		idx = numId++;
		sTable[idx].symbol = id;
		sTable[idx].val = val;
	}
	return 0;
}

char *infixToPostfix(char *a)
{
	int i, N = strlen(a);
	Stack *operand = STACKinit(N);
	Stack *operator = STACKinit(N);
	char *op, *exp;
	char *operand1;
	char *operand2;
	for (i = 0; i < N; i++)
	{
		switch (a[i]) {
		case '(':
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
			op = calloc(2, 1);
			op[0] = a[i];
			STACKpush(operator, op);
			break;

		case ')':
			op = STACKpop(operator);
			operand2 = STACKpop(operand);
			operand1 = STACKpop(operand);
			exp = calloc(strlen(operand1) + strlen(operand2) + 4, 1);
			sprintf(exp, "%s %s %c", operand1, operand2, op[0]);
			STACKpush(operand, exp);
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
				while (a[j] >= 65 && a[j] <=122)
					j++;
				char *key = calloc(j - i + 2, 1);
				memcpy(key, &a[i], j - i + 1);
				STACKpush(operand, key);
			}
			break;
		}
	}
	char *output = STACKpop(operand);
	return output;
}

static inline int isIdentifier(char *str)
{
	if ((str[0] >= 'A' && str[0] <= 'Z')
	    || (str[0] >= 'a' && str[0] <= 'z'))
		return 1;
	return 0;
}

static inline int isNum(char *str)
{
	if ((str[0] >= '0') && (str[0] <= '9'))
		return 1;
	return 0;
}

void evalPostfix(char *a)
{
	int N = strlen(a);
	Stack *evalStack = STACKinit(N);
	char *operand1, *operand2, *buf;
	int val1, val2;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == '+') {
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);

			if (isIdentifier(operand1)) {
				val1 = getValFromStable(operand1);
			} else if (isNum(operand1)) {
				val1 = atoi(operand1);
			}

			if (isIdentifier(operand2)) {
				val2 = getValFromStable(operand2);
			} else if (isNum(operand2)) {
				val2 = atoi(operand2);
			}

			buf = calloc(10, 1);
			sprintf(buf, "%d", val1 + val2);
			STACKpush(evalStack, buf);	
		}

		if (a[i] == '*') {
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);

			if (isIdentifier(operand1)) {
				val1 = getValFromStable(operand1);
			} else if (isNum(operand1)) {
				val1 = atoi(operand1);
			}

			if (isIdentifier(operand2)) {
				val2 = getValFromStable(operand2);
			} else if (isNum(operand2)) {
				val2 = atoi(operand2);
			}

			buf = calloc(10, 1);
			sprintf(buf, "%d", val1 * val2);
			STACKpush(evalStack, buf);	
		}

		if (a[i] == '=') {
			operand2 = STACKpop(evalStack);
			operand1 = STACKpop(evalStack);
			assert(isIdentifier(operand1));

			if (isIdentifier(operand2)) {
				val2 = getValFromStable(operand2);
			} else if (isNum(operand2)) {
				val2 = atoi(operand2);
			}

			setValToStable(operand1, val2);

		}

		if (isIdentifier(&a[i])) {
			int j = i;
			while (isIdentifier(&a[++j]));
			char *id = calloc(j-i+1, 1);
			memcpy(id, &a[i], j - i);
			STACKpush(evalStack, id);
		}

		if (isNum(&a[i])) {
			int j = i;
			while (isNum(&a[++j]));
			char *num = calloc(j-i+1, 1);
			memcpy(num, &a[i], j - i);
			STACKpush(evalStack, num);
		}
	}
	if (!STACKempty(evalStack))
		printf("%d\n", atoi(STACKpop(evalStack)));	
}
