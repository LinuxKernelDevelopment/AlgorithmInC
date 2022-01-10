#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

int evalPost(char *a)
{
	int i, N = strlen(a);
	Stack *st = STACKinit(N);
	for (i = 0; i < N; i++)
	{
		if (a[i] == '+')
			STACKpush(st, STACKpop(st) + STACKpop(st));
		if (a[i] == '*')
			STACKpush(st, STACKpop(st) * STACKpop(st));
		if (a[i] == '-') {
			Item op2 = STACKpop(st);
			Item op1 = STACKpop(st);
			STACKpush(st, op1 - op2);
		}
		if (a[i] == '/') {
			Item op2 = STACKpop(st);
			Item op1 = STACKpop(st);
			STACKpush(st, op1 / op2);
		}
		if ((a[i] >= '0') && (a[i] <= '9'))
			STACKpush(st, 0);
		while ((a[i] >= '0') && (a[i] <= '9'))
			STACKpush(st, 10*STACKpop(st) + (a[i++]-'0'));
	}
	return STACKpop(st);
}

int infixToPostfix(char *a)
{
	int i, N = strlen(a);
	Stack *st = STACKinit(N);
	for (i = 0; i < N; i++)
	{
		if (a[i] == ')')
			printf("%c ", STACKpop(st));
		if ((a[i] == '+') || (a[i] == '*'))
			STACKpush(st, a[i]);
		if ((a[i] >= '0') && (a[i] <= '9'))
			printf("%c ", a[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int val = evalPost(argv[1]);
	printf("%d\n", val);
	infixToPostfix(argv[2]);
	return 0;
}
