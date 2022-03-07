#include <stdio.h>
#include "floatvector.h"

int main(void)
{
	float p[10] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	FV fv = initFloatVector(p, 10);
	printFloatVector(fv);
	addFn(fv, 1.0);
	printFloatVector(fv);
	return 0;
}
