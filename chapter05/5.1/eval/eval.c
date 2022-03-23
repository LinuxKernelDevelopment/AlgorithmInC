#include <stdio.h>

char *a; int i;
int eval()
{
	int x = 0;
	while (a[i] == ' ') i++;
	if (a[i] == '+')
	{ i++; return eval() + eval(); }
	if (a[i] == '*')
	{ i++; return eval() * eval(); }
	while ((a[i] >= '0') && (a[i] <= '9'))
		x = 10 * x + (a[i++] - '0');
	return x;
}

int main(int argc, char *argv[])
{
	char *str = argv[1];
	int ret;
	printf("%s\n", str);
	a = str;
	ret = eval();
	printf("%d\n", ret);
	return 0;
}
