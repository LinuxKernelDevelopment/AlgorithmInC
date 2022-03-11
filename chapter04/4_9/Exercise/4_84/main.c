#include <stdio.h>
#include "set.h"

int main()
{
	Set a = setInit(10);
	setEnter(a, 5);
	printSet(a);
	Set b = setInit(10);
	setEnter(b, 6);

	Set c = setUnion(a, b);
	Set d = setComplement(a);
	Set e = setDifference(a, b);
	printSet(c);
	printSet(d);
	printSet(e);
	setDestroy(a);
	setDestroy(b);
	setDestroy(c);
	setDestroy(d);
	setDestroy(e);
	return 0;
}
