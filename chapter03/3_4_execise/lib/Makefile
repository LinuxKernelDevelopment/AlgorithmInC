.PHONY: main
INCLUDE=../include
main: list.o doublelist.o
%.o : %.c $(INCLUDE)
	gcc -g -c $(INCLUDE:%=-I %) $<
