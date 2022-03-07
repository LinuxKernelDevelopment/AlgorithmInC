
.PHONY: main

SOURCE := $(wildcard ./*.c)
TARGET := $(SOURCE:.c=.o)
INC := ../4_76/
VPATH := ../4_76/

main: $(TARGET) $(LINK_OBJ) largeint.a
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -I$(INC) -g -c $^

clean:
	$(RM) $(TARGET) main
