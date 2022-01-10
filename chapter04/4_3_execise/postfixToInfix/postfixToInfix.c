#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

void postfixToInfix(char *a)
{
	int N = strlen(a);
	STACKinit(N);
	for (int i = 0; i < N; i++) {
		if ((a[i] == '+') || (a[i] == '*') || (a[i] == '-') || (a[i] == '/')) {
			char *operand2 = STACKpop();
			char *operand1 = STACKpop();
			char *result = calloc(strlen(operand1) + 6 + strlen(operand2), 1);
			sprintf(result, "(%s %c %s)", operand1, a[i], operand2);
			STACKpush(result);
		}
		if ((a[i] >= '0') && (a[i] <= '9')) {
			int j;
			for (j = i; j < N && a[j] != ' '; j++);
			char *num = calloc(j - i + 1, 1);
			memcpy(num, &a[i], j - i);
			STACKpush(num);
			i = j;
		}
	}
}

int main(int argc, char *argv[])
{
	char *a = argv[1];
	postfixToInfix(a);
	printf("%s\n", STACKpop());
	return 0;
}
