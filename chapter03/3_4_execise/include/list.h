#define itemType int
typedef struct node* link;
struct node { itemType item; link next; };
typedef link Node;
void initNodes(int);
link newNode(int);
void freeNode(link);
void insertNode(link, link);
link deleteNext(link);
link Next(link);
itemType Item(link);
link initDummyList();
link initNoDummyList();
void dumpList(link);
void dumpNoDummyList(link);
int exchange(link, link);
void insertNoDummyNode(link *x, link t);
int freeList(link t);
