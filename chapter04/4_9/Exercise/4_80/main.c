#include <stdio.h>
#include "matrices.h"

int main(void)
{
	MA ma, mb, mc, md, me, mf, mg;
	int a[2][2] = { {1, 2},
			 {3, 4} };
	int b[2][2] = { {2, 3},
			 {4, 5} };
	int f[2][2] = { {10, 20},
		        {30, 40} };

	ma = initMatrice((int *)a, 2, 2);
	mb = initMatrice((int *)b, 2, 2);
	mf = initMatrice((int *)f, 2, 2);

	mc = matriceAddSub(ma, mb, 1);
	md = matriceAddSub(ma, mb, 0);
	me = matriceMul(ma, mb);
	mg = matriceDiv(mf, 5);
	printMatrice(mc);
	printMatrice(md);
	printMatrice(me);
	printMatrice(mg);
	destroyMatrice(ma);
	destroyMatrice(mb);
	destroyMatrice(mc);
	destroyMatrice(md);
	destroyMatrice(me);
	return 0;
}
