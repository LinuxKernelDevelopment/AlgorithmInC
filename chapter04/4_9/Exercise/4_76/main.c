#include <stdio.h>
#include "largeint.h"

int main(void)
{
	char *a = "9999999999989999991234567890";
	char *b = "9876543210";
	LI lia, lib, lic;

	lia = LIinit(a);
	lib = LIinit(b);

	lic = LIadd(lia, lib);

	printLI(lic);
	printf("\n");
	return 0;
}
