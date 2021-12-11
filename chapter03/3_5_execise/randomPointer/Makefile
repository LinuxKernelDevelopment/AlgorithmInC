.PHONY: main

main: randomPointer
INCLUDE = ../../../lib/include/ include/
randomPointer: randomPointer.o ../../../lib/libs/random.a

%.o : %.c
	gcc -g -c $(INCLUDE:%=-I %) $<

clean:
	$(RM) *.o randomPointer
