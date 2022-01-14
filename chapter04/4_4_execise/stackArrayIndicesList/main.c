#include <stdio.h>
#include "Item.h"
#include "STACK.h"

int main(int argc, char *argv[])
{
	STACKinit(100);
	for (int i = 0; i < 100; i++) {
		STACKpush(i);
	}
	for (int i = 0; i < 100; i++) {
		Item tmp = STACKpop();
		printf("%d ", tmp);
	}
	printf("\n");
	printf("%d\n", count());
	return 0;
}
