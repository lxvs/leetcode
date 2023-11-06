.PHONY: all clean debug generate_version

SHELL := /bin/sh

EXEC := lcd

GCC_FLAGS := -Wall -Iinclude

SOURCE_FILES := driver.c easy/*.c medium/*.c hard/*.c
SOURCE_FILES_LIB := lib/*.c

HEADERS := easy/*.h medium/*.h hard/*.h
HEADERS_LIB := include/lib/*.h

GENERATE_VERSION := sh utils/write_version.sh

all: generate_version $(SOURCE_FILES) $(SOURCE_FILES_LIB) $(HEADERS) $(HEADERS_LIB)
	gcc $(GCC_FLAGS) $(DEBUG_FLAGS) $(ADDRESS_SANITIZER_FLAGS) $(CFLAGS) $(SOURCE_FILES) $(SOURCE_FILES_LIB) -o $(EXEC)

clean:
	rm $(EXEC)

debug: export DEBUG_FLAGS := -DDEBUG
debug: export ADDRESS_SANITIZER_FLAGS := -fsanitize=address -static-libasan -g -fno-omit-frame-pointer
debug: all

generate_version:
	$(GENERATE_VERSION)
