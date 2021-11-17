.PHONY: all clean

all: *.c *.h
	gcc -Wall *.c -o driver

clean:
	printf "wipe wipe~\n"
