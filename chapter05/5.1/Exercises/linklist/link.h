typedef struct node *link;
struct node { int item; link next; };
int count(link x);
void traverse(link h, void (*visit)(link));
void traverseR(link h, void (*visit)(link));
link delete(link x, Item v);
void deleteLast(link x);
void visit(link x);
