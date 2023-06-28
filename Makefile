CC=g++
CFLAGS=-Wall -Wextra
LDFLAGS=-lX11

keyboard-lock: keyboard-cleaner.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

.PHONY: clean

clean:
	rm -f keyboard-cleaner
