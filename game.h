#ifndef TTT_GAME_H
#define TTT_GAME_H

enum state { X, O, DRAW, NONE };

typedef struct {
    enum state **board;     // 2D-array of every cell

    struct {
        int width, height;
    } window;

    struct {
        int width, height;  // Width and height of a single cell in pixels
    } cell;

    struct {
        enum state current;
        enum state won;
    } player;

    int length;             // Amount of cells in a single row
    int streak;             // How many cells to put in a row to win
} Game;

#endif
