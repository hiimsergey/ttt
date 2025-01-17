SRC = main.c draw.c logic.c screen.c

all: main.c
	gcc -o ttt $(SRC) -Wall -lraylib -lm
	./ttt
