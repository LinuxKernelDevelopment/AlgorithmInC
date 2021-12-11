#define itemType int
typedef struct doubleNode* doubleLink;
struct doubleNode { itemType item; doubleLink prev; doubleLink next; };
doubleLink newNode(int itemValue);
void freeNode(doubleLink t);
void insertNode(doubleLink x, doubleLink t);
doubleLink initDummyList();
void dumpList(doubleLink t);
void exchangeDouble(doubleLink a, doubleLink b);
