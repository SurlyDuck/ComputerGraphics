.PHONY: clear all

CFLAGS = -ggdb -std=c99 -Wall -Wextra -pedantic

all: run

run: dda
	./dda

dda: dda.c
	cc $(CFLAGS) -o dda dda.c ../include/image.c

clear: dda
	rm dda
