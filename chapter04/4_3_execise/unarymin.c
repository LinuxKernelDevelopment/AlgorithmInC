#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

void infixToPostfix(char *a)
{
	int i, N = strlen(a);
	STACKinit(N);
	int minus = 0;
	int parenthess = 0;
	int tmp;
	int currentLevel = 0;
	for (i = 0; i < N; i++)
	{
		if (a[i] == '(') {
			STACKpush(a[i]);
		}
		if (a[i] == ')') {
			tmp = STACKpop();
			while (tmp != '(') {
				printf("%c ", tmp);
				tmp = STACKpop();
			}
		}
		if ((a[i] == '+') || (a[i] == '*') || (a[i] == '/')) {
			currentLevel = parenthess;
			STACKpush(a[i]);
		}
		if (a[i] == '-') {
			if (a[i+1] != ' ')
				minus = minus ^ 0x01;
			else
				STACKpush(a[i]);
		}
		if ((a[i] >= '0') && (a[i] <= '9')) {
			if (!minus)
				printf("%c ", a[i]);
			else
				printf("-%c ", a[i]);
			minus = 0;
		}
		
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	char *a = argv[1]; int i, N = strlen(a);
	infixToPostfix(a);
	printf("\n");
}
