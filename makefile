.PHONY: all clean debug cat install uninstall

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

EXEC := lcdriver

all: *.c *.h lib/*.c lib/*.h
	gcc -Wall *.c lib/*.c -o $(EXEC)

clean:
	rm $(EXEC)

debug:
	gcc -DDEBUG=1 -Wall *.c lib/*.c -o $(EXEC)

cat:
	@cat $(CAT) | clip.exe

install: $(EXEC)
	install -d $(DESTDIR)$(PREFIX)/bin/
	install $(EXEC) $(DESTDIR)$(PREFIX)/bin/

uninstall:
	rm $(DESTDIR)$(PREFIX)/bin/$(EXEC)
