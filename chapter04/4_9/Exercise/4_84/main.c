#include <stdio.h>
#include "set.h"

int main()
{
	Set a = setInit(10);
	setEnter(a, 5);
	printSet(a);
}
