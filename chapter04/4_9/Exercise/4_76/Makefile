
.PHONY: main

SOURCE := $(wildcard ./*.c)
TARGET := $(SOURCE:.c=.o)

main: $(TARGET) $(LINK_OBJ)
	$(CC) $^ -o $@

%.o : %.c 
	$(CC) -g3 -c $^

clean:
	$(RM) $(TARGET) main

library: largeint.o
	$(AR) rcs largeint.a $^

