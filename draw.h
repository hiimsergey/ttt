#ifndef TTT_DRAW_H
#define TTT_DRAW_H

#include <raylib.h>
#include "game.h"

// Draws a grid between the cells in the color of the current player.
void draw_grid(const Game *game);
void draw_tokens(const Game *game);

#endif
