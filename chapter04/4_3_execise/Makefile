TARGET := peval intopos unarymin
main: $(TARGET)

peval : ../stackArray.o peval.o

intopos : ../stackArray.o intopos.o

unarymin : ../stackArray.o unarymin.o

%.o : %.c
	$(CC) -I../include -g -c $^

clean:
	$(RM) -f $(TARGET) *.o
