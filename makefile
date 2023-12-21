.PHONY: all clean debug generate_version

SHELL := /bin/sh
CC := gcc

EXEC := lcd

export CFLAGS_LOCAL := -Wall -Iinclude

DEBUG_FLAGS := -DDEBUG
DEBUGGER_FLAGS := -fdiagnostics-color=always -g
ADDRESS_SANITIZER_FLAGS := -fsanitize=address -static-libasan -g -fno-omit-frame-pointer

SOURCE_FILES := driver.c easy/*.c medium/*.c hard/*.c
SOURCE_FILES_LIB := lib/*.c

HEADERS := easy/*.h medium/*.h hard/*.h
HEADERS_LIB := include/lib/*.h

GENERATE_VERSION := $(SHELL) utils/write-version.sh

all: generate_version $(SOURCE_FILES) $(SOURCE_FILES_LIB) $(HEADERS) $(HEADERS_LIB)
	$(CC) $(CFLAGS_LOCAL) $(CFLAGS) $(SOURCE_FILES) $(SOURCE_FILES_LIB) -o $(EXEC)

clean:
	rm $(EXEC)

debug: CFLAGS_LOCAL += $(DEBUG_FLAGS) $(ADDRESS_SANITIZER_FLAGS)
debug: all

debugger: CFLAGS_LOCAL += $(DEBUG_FLAGS) $(DEBUGGER_FLAGS)
debugger: all

generate_version:
	$(GENERATE_VERSION)
