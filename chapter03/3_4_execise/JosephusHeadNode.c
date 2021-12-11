#include <stdlib.h>
#include <stdio.h>
typedef struct node *link;
struct node { int item; link next; };

void dumpList(link head)
{
   for (link t = head->next; t != head; t = t->next) {
      printf("%d ", t->item);
   }
   printf("\n");
}

int main(int argc, char *argv[])
{ int i, N = atoi(argv[1]), M = atoi(argv[2]);
  link t = malloc(sizeof *t), x = t;
  t->item = -1, t->next = t;
  for (i = 1; i <= N; i++)
  {
     x = (x->next = malloc(sizeof *x));
     x->item = i; x->next = t;
  }
  x = t;
  while (x != x->next->next)
  {
     for (i = 1; i < M; i++) {
        if (x->next == t)
	   x = x->next;
        x = x->next;
     }
     if (x->next == t)
	     x = x->next;
     x->next = x->next->next;
     N--;
  }
  printf("%d\n", x->next->item);
  return 0;
}
