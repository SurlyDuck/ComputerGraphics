.PHONY: clear all run

CFLAGS= -I -ggdb -std=c99 -Wall -Wextra -pedantic
LFLAGS= -L../libs/ -lraylib -lX11 -lm -lGL

all: primitives run

#TODO: core will be a dynamic lib
primitives: primitives.c
	$(CC) $(CFLAGS) -o primitives primitives.c ../include/core.c ../include/display.c $(LFLAGS)

run: 
	./primitives

clear:
	rm ./primitives
