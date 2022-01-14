#include <stdlib.h>
#include "Item.h"
#include "STACK.h"
static Item *s;
static int N;
void STACKinit(int maxN)
  { s = malloc(maxN * sizeof(Item)); N = 0; }

int count()
  { return N; }
int STACKempty()
  { return count() == 0; }

void STACKpush(Item item)
  { s[N++] = item; }

Item STACKpop()
  { return s[--N]; }
