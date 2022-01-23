.PHONY: target

VPATH = ../../../lib/libs/:../../../lib/libs/hashtable/
target : main

main : main.o randomQueue.o random.a hash.o

randomQueue.o : randomQueue.c
	$(CC) -g -c $< -I../../../lib/include/ -I../../../lib/libs/hashtable/

main.o : main.c
	$(CC) -g -c $<

clean:
	$(RM) *.o main
