#ifndef __SET_H__
#define __SET_H__
typedef struct set *Set;
Set setInit(int);
void setEnter(Set, int);
Set setUnion(Set, Set);
Set setIntersection(Set, Set);
Set setComplement(Set);
Set setDifference(Set, Set);
void printSet(Set);
#endif
