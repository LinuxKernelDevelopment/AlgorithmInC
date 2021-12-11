#ifndef _ARRAYLIST_
#define _ARRAYLIST_
#define ELEM_DNE -1
#define ELEM_END -2 
#define itemType int
typedef struct node* elem;
struct node
{
	itemType item;
	int next;
};

struct globalTable {
	elem nodeTable;
	int num;
};

void initNodes(int);
elem newNode(int);
void freeNode(elem);
void insertNext(elem, elem);
elem deleteNext(elem);
elem Next(elem);
int Item(elem);
void dumpNodes(elem);
#endif
