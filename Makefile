CC ?= gcc
SRC = main.c draw.c logic.c screen.c

all: main.c
	$(CC) -o ttt $(SRC) -Wall -lraylib -lm
	./ttt

semistatic:
	$(CC) -o ttt $(SRC) -Lexternal/raylib/install/lib/ -Iexternal/raylib/install/include/ -lraylib -lm
