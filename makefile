.PHONY: all clean debug

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

EXEC := lcd

GCC_FLAGS := -Wall -I.
ADDRESS_SANITIZER_FLAGS := -fsanitize=address -static-libasan -g -fno-omit-frame-pointer

SOURCE_FILES := driver.c easy/*.c medium/*.c hard/*.c
SOURCE_FILES_LIB := lib/*.c

HEADERS := easy/*.h medium/*.h hard/*.h
HEADERS_LIB := lib/*.h

all: $(SOURCE_FILES) $(SOURCE_FILES_LIB) $(HEADERS) $(HEADERS_LIB)
	gcc $(GCC_FLAGS) $(SOURCE_FILES) $(SOURCE_FILES_LIB) -o $(EXEC)

clean:
	rm $(EXEC)

debug:
	gcc $(GCC_FLAGS) -DDEBUG $(SOURCE_FILES) $(SOURCE_FILES_LIB) -o $(EXEC) $(ADDRESS_SANITIZER_FLAGS)
