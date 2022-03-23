#include <stdio.h>
#include <math.h>
#include "largeint.h"

/*double factorial(double n)
{
	if (n == 1.0)
		return 1.0;

	return n * factorial(n - 1.0);
}

double modM(double n, double m)
{
	double val;

	val = factorial(n);

	return val % m;
}*/


LI factorial(LI num)
{
	LI one = LIinit("1");

	if (isLIone(num))
		return num;

	LI prev = LIsub(num, one);

	return LImult(num, factorial(prev));
}

LI modM(LI num, LI d)
{
	LI quot, remain;
	LI r = factorial(num);

	LIdiv(r, d, &quot, &remain);
	return remain;
}

int main()
{
	LI a = LIinit("1000");
	LI b = LIinit("997");

	LI a1 = LIinit("1000");
	LI c, d;

	//LI r = factorial(a);

	//LIdiv(r, b, &c, &d);
	LI r = modM(a, b);
	printLI(r);
	printf("\n");

	LI q = modM(a1, b);
	printLI(q);
	printf("\n");

	return 0;
}
