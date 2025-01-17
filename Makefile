CC ?= gcc
SRC = main.c draw.c logic.c screen.c

all: main.c
	$(CC) -o ttt $(SRC) -Wall -Wextra \
		-Lexternal/raylib/install/lib/ -Iexternal/raylib/install/include/ \
		-lraylib -lm
	./ttt

semistatic:
	$(CC) -o ttt $(SRC) -O3 -Wall -Wextra \
		-Lexternal/raylib/install/lib/ -Iexternal/raylib/install/include/ \
		-lraylib -lm
