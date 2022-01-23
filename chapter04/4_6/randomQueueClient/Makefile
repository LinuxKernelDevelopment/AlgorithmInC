.PHONY: target

VPATH = ../../../lib/libs/:../../../lib/libs/hashtable/
target : lottery

lottery: lottery.o randomQueueList.o random.a

randomQueueList.o : randomQueueList.c
	$(CC) -g -c $< -I../../../lib/include/

lottery.o : lottery.c
	$(CC) -g -c $<

clean:
	$(RM) *.o lottery
