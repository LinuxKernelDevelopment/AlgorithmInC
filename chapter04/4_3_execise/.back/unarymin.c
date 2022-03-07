#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

void infixToPosfix(char *a)
{
	int i, N = strlen(a);
	int operand1, operand2;
	char op;
	int lastNum = 0;
	int tmp;
	int parenthese = 0;
	STACKinit(N);
	for (i = 0; i < N; i++)
	{
		switch (a[i]) {
		case ')':
			parenthese--;
			operand1 = STACKpop();
			op = STACKpop();
			operand2 = STACKpop();
			printf("%d %d %c ", operand1, operand2, op);
			lastNum = 0;
			break;

		case '(':
			lastNum = 0;
			parenthese++;
			break;

		case ' ':
			lastNum = 0;
			break;

		case '+':
		case '*':
		case '/':
			STACKpush(a[i]);
			break;

		case '-':
			if (lastNum == 0) {
				tmp = STACKpop();
				STACKpush(-tmp);
				break;
			}
			// fall through

		default:
			if (lastNum) {
				if ((a[i] >= '0') && (a[i] <= '9')) {
					STACKpush(10 * STACKpop() + (a[i] - '0'));
					lastNum = 1;
				} else 
					lastNum = 0;	
			} else {
				if ((a[i] > '0') && (a[i] <= '9')) {
					STACKpush(a[i]);
					lastNum = 1;
				} else
					lastNum = 0;
			}
			break;
				
		}
	}
}

int main(int argc, char *argv[])
{
	char *a = argv[1]; int i, N = strlen(a);
	infixToPosfix(a);
	printf("\n");
}
