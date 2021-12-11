.PHONY: arrayListMain

INCLUDE := ../../../lib/include/
TARGET := arrayListMain

arrayListMain : main.o arrayList.o ../../../lib/libs/random.a
	$(CC) -g $^ -o $@

%.o : %.c $(INCLUDE)
	$(CC) -g -c $(INCLUDE:%=-I %) $<
