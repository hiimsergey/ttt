CC ?= gcc
SRC = main.c draw.c logic.c screen.c

# Install Raylib yourself – dynamic linking
all:
	$(CC) -o ttt $(SRC) -Wall -Wextra \
		-Lexternal/raylib/install/lib/ -Iexternal/raylib/install/include/ \
		-lraylib -lm
	./ttt

# If you have Raylib installed on the system – dynamic linking
dyn:
	$(CC) -o ttt $(SRC) -lraylib -lm -O3
	./ttt

# Install Raylib yourself – semistatic linking
semistatic:
	$(CC) -o ttt $(SRC) -O3 -Wall -Wextra \
		-Lexternal/raylib/install/lib/ -Iexternal/raylib/install/include/ \
		-lraylib -lm
