#include <stdio.h>
#include "string.h"

int main(void)
{
	String a;
	String b, c;

	a = StringInit("fuck ");
	b = StringInit("you");
	c = StringCat(a, b);
	StringPrint(c);
	printf("%d\n", StringCmp(a, b));
	StringCopy(b, a);
	StringPrint(b);
	StringDestroy(a);
	StringDestroy(b);
	StringDestroy(c);
	return 0;
}
