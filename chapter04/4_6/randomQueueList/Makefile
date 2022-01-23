.PHONY: target

VPATH = ../../../lib/libs/:../../../lib/libs/hashtable/
target : main

main : main.o randomQueueList.o random.a

randomQueueList.o : randomQueueList.c
	$(CC) -g -c $< -I../../../lib/include/

main.o : main.c
	$(CC) -g -c $<

clean:
	$(RM) *.o main
