#ifndef TTT_SCREEN_H
#define TTT_SCREEN_H

#include <raylib.h>
#include "game.h"

// Draws the settings screen before and after each game.
void screen_end(const Game *game, Rectangle *board_length_rec, Rectangle *win_streak_rec);
void screen_listen_input(
    Game *game,
    const Rectangle *board_length_rec,
    const Rectangle *win_streak_rec
);

#endif
