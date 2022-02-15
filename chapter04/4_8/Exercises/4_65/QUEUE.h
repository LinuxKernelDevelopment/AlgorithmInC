typedef struct queue *QUEUE;
QUEUE *QUEUEinit(int maxN);
int QUEUEempty(QUEUE *q);
void QUEUEput(QUEUE *q, Item item);
Item QUEUEget(QUEUE *q);
