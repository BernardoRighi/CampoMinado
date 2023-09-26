# Definições

CFLAGS=-Wall -Wextra -g -std=c99


# Regras

all: main

main: utils.o gfx.o main.o game.o screens.o
	gcc utils.o gfx.o main.o game.o screens.o -o main

utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c
	
screens.o: screens.c screens.h
	gcc $(CFLAGS) -c screens.c

gfx.o: gfx.c gfx.h
	gcc $(CFLAGS) -c gfx.c 

main.o: main.c utils.h gfx.h 
	gcc $(CFLAGS) -c main.c
	
utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c
	
game.o: game.h game.c
	gcc $(CFLAGS) -c game.c 

clean:
	rm -f main *.o *~

