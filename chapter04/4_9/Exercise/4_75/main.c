#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"

int main(int argc, char *argv[])
{
	/*Poly t, p, q, x, r, s;
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
	q = POLYadd(q, POLYterm(24, 24));*/
	//r = POLYadd(p, q);
	//showPOLY(r);

	/*showPOLY(p);
	showPOLY(q);
	s = POLYsub(p, q);
	showPOLY(s);*/

	//r = POLYignore(r, 100);
	//showPOLY(r);
	/*for (int i = 0; i < 5; i++) {
		x = POLYmult(t, x);
		showPOLY(x);
	}*/

	Poly p, q, r, reminder;

	/*p = POLYadd(POLYterm(2, 4), POLYterm(1, 2));
	p = POLYadd(p, POLYterm(3, 0));

	q = POLYadd(POLYterm(1, 2), POLYterm(-1, 0));*/

	p = POLYadd(POLYterm(1, 2), POLYterm(-1, 0));
	q = POLYadd(POLYterm(1, 1), POLYterm(1, 0));

	//POLYdivision(p, q, &r, &reminder);
	r = POLYcomposition(p, q);

	showPOLY(p);
	showPOLY(q);
	showPOLY(r);
	//showPOLY(reminder);
	return 0;
}
