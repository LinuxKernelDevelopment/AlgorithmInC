#include <stdio.h>
#include "largeint.h"

int main(void)
{
	char *a = "27838129730676270000372617";
	char *b = "3826198749007382";

	LI lia, lib, lic;
	lia = LIinit(a);
	lib = LIinit(b);
	
	lic = LIsub(lia, lib);
	printLI(lic);
	printf("\n");
	/*char *d = "73812738127";
	char *e = "28173821731389127";
	LI lia, lib, lic, lid, lie, lif;

	lia = LIinit(a);
	lib = LIinit(b);
	lid = LIinit(d);
	lie = LIinit(e);

	lic = LImult(lib, lia);
	lif = LImult(lid, lie);
	printLI(lic);
	printf("\n");
	printLI(lif);
	printf("\n");
	return 0;*/
	/*char *a = "9999999999989999991234567890";
	char *b = "9876543210";
	LI lia, lib, lic;

	lia = LIinit(a);
	lib = LIinit(b);

	lic = LIadd(lib, lia);

	printLI(lic);
	printf("\n");
	LIdestroy(lia);
	LIdestroy(lib);
	LIdestroy(lic);
	return 0;*/
}
