#ifndef TTT_LOGIC_H
#define TTT_LOGIC_H

#include "game.h"

// Fills the entire game board with empty cells `NONE`
void logic_clear_board(Game *game);

// Handles clicking cells pressing 'q'
void logic_listen_input(Game *game);

#endif
