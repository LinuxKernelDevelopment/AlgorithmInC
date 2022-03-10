#include <stdio.h>
#include "string.h"

int main(void)
{
	String a;
	String b, c;

	a = StringInit("fuck ");
	b = StringInit("you");
	c = StringCat(a, b);

	//StringPrint(a);
	//printf("%d\n", StringCmp(a, b));
	//StringCopy(b, a);
	StringPrint(c);
	StringDestroy(a);
	StringDestroy(b);
	return 0;
}
