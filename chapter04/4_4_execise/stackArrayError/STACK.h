#ifndef __STACK_H__
#define	__STACK_H__

void STACKinit(int);
int count();
void STACKerror();
int STACKempty();
void STACKpush(Item item);
Item STACKpop();
#endif
