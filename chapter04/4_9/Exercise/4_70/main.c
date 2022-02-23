#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"

int main(int argc, char *argv[])
{
	Poly t, p, q, x;
	t = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
	x = t;

	p = POLYadd(POLYterm(100, 100), POLYterm(50, 50));
	p = POLYadd(p, POLYterm(25, 25));
	p = POLYadd(p, POLYterm(1, 99));
	p = POLYadd(p, POLYterm(1, 0));

	q = POLYadd(POLYterm(1000, 1000), POLYterm(500, 500));
	q = POLYadd(q, POLYterm(250, 250));
	q = POLYadd(q, POLYterm(99, 99));
	q = POLYadd(q, POLYterm(49, 49));
	q = POLYadd(q, POLYterm(24, 24));
	showPOLY(POLYadd(p, q));

	for (int i = 0; i < 5; i++) {
		x = POLYmult(t, x);
		showPOLY(x);
	}	
	return 0;
}
