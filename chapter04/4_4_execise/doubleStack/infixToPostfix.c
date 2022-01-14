#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "doubleStack.h"

char *infixToPostfix(char *a)
{
	int i, N = strlen(a);
	STACKinit(N);

	for (i = 0; i < N; i++) {
		if (a[i] == ')')
			printf("%c ", headPop());
		if ((a[i] == '+') || (a[i] == '*')) {
			headPush(a[i]);
		}
		if ((a[i] >= '0') && (a[i] <= '9'))
			printf("%c ", a[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	infixToPostfix(argv[1]);
	return 0;
}
