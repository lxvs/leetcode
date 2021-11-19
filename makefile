.PHONY: all clean debug cat

all: *.c *.h lib/*.c lib/*.h
	gcc -Wall *.c lib/*.c -o driver

clean:
	rm driver

debug:
	gcc -DDEBUG=1 -Wall *.c lib/*.c -o driver

cat:
	@cat $(CAT) | clip.exe
