typedef struct stack *STACK;
STACK STACKinit(int maxN);
int STACKempty(STACK s);
void STACKpush(STACK s, Item item);
Item STACKpop(STACK s);
