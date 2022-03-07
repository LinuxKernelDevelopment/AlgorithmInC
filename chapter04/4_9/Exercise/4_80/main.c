#include <stdio.h>
#include "matrices.h"

int main(void)
{
	MA ma, mb, mc;
	int a[2][2] = { {1, 2},
			 {3, 4} };
	int b[2][2] = { {2, 3},
			 {4, 5} };

	ma = initMatrice(a, 2, 2);
	mb = initMatrice(b, 2, 2);

	mc = matriceAddition(ma, mb);
	printMatrice(mc);
	return 0;
}
