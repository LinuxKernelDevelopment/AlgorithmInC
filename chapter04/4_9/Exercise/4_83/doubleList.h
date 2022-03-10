#ifndef __DOUBLE_LIST_H__
#include "Item.h"
typedef struct Listnode *link;
link ListInit(void);
link NEW(Item item, link prev);
link DEL(link x);
void ListDestroy(link t);
int ListCmp(link a, link b);
void ListFun(link a, void (*fn)(char));
Item ListNextVal(link *t);
void ListLinkTail(link, link);
#endif
