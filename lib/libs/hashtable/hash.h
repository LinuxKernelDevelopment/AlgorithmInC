#ifndef __HASH_H__

void hashInit(int Num);

int hashPut(Item, int (*hashfun)(Item));

int hashGet(unsigned int key);

int hashNumGet(void);

#endif
