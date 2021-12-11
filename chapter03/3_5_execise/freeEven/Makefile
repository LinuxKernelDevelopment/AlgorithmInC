.PHONY: main listlib

INCLUDE := include/ ../../include/

main: listlib freeEven

freeEven : freeEven.o lib/list.o 
listlib:
	$(MAKE) -C lib/

%.o : %.c
	gcc -g -c -Iinclude/ $<
