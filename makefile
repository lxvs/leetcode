.PHONY: all clean debug

all: *.c *.h lib/*.c lib/*.h
	gcc -Wall *.c lib/*.c -o driver

clean:
	rm driver

debug:
	gcc -DDEBUG=1 -Wall *.c lib/*.c -o driver
