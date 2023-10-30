.PHONY: all clean debug

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

EXEC := lcdriver

all: *.c *.h lib/*.c lib/*.h
	gcc -Wall *.c lib/*.c -o $(EXEC)

clean:
	rm $(EXEC)

debug:
	gcc -DDEBUG -Wall *.c lib/*.c -o $(EXEC) -fsanitize=address -static-libasan -g -fno-omit-frame-pointer
