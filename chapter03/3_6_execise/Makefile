.PHONY: main

TARGET := chrcnt palindrome kmpmatch

OBJFILE := $(addsuffix .o,$(TARGET))
main: $(TARGET)

chrcnt: chrcnt.o

palindrome: palindrome.o

clean:
	$(RM) $(TARGET) $(OBJFILE)
