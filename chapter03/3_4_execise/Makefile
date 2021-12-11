.PHONY: main listlib 

INCLUDE = include/  ../../include/
TARGET := largest smallest moveven exchange removeNode makeCopy reversehead listsort exchangeDouble
main: listlib $(TARGET)
largest : largest.o lib/list.o ../../lib/libs/random.a

smallest : smallest.o lib/list.o ../../lib/libs/random.a

moveven : moveven.o lib/list.o ../../lib/libs/random.a
exchange : exchange.o lib/list.o ../../lib/libs/random.a
copyList : copyList.o lib/list.o ../../lib/libs/random.a
removeNode : removeNode.o lib/list.o ../../lib/libs/random.a
makeCopy : makeCopy.o lib/list.o ../../lib/libs/random.a

#makeCopy : makeCopy.o lib/list.o ../../lib/libs/random.a
#	$(CC) -g $(INCLUDE:%=-I %) $^ -o $@

reversehead : reversehead.o lib/list.o ../../lib/libs/random.a

listsort : listsort.o lib/list.o ../../lib/libs/random.a

exchangeDouble: exchangeDouble.o lib/doublelist.o ../../lib/libs/random.a

listlib:
	$(MAKE) -C lib/

%.o : %.c $(INCLUDE)
	gcc -g -c $(INCLUDE:%=-I %) $<
clean:
	$(RM) *.o $(TARGET)
