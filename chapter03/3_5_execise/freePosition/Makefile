.PHONY: main listlib

INCLUDE := include/ ../../include/

main: listlib freePosition

freePosition : freePosition.o lib/list.o 
listlib:
	$(MAKE) -C lib/

%.o : %.c
	gcc -g -c -Iinclude/ $<
