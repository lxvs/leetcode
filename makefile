.PHONY: all clean

all: *.c *.h lib/*.c lib/*.h
	gcc -Wall *.c lib/*.c -o driver

clean:
	printf "wipe wipe~\n"
