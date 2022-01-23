.PHONY: target

VPATH = ../../../lib/libs/:../../../lib/libs/hashtable/
target : poker

poker : poker.o randomQueueList.o random.a

randomQueueList.o : randomQueueList.c
	$(CC) -g -c $< -I../../../lib/include/

poker.o : poker.c
	$(CC) -g -c $<

clean:
	$(RM) *.o poker
