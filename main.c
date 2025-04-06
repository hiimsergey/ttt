#include <stddef.h>
#include <raylib.h>
#include "game.h"
#include "draw.h"
#include "logic.h"
#include "screen.h"

#define TSODINGGRAY (Color) { 0x18, 0x18, 0x18, 0xff }

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(512, 512, "ttt v0.2.0");

    Game game = {
        .board = MemAlloc(9 * sizeof(enum state *)),
        .player.current = NONE,
        .player.won = NONE,
        .length = 3,
        .streak = 3
    };
    if (game.board == NULL) {
        TraceLog(LOG_ERROR, "Failed to allocate resources for the game board!");
        CloseWindow();
        return 1;
    }

    while (!WindowShouldClose()) {
        game.window.width = GetScreenWidth();
        game.window.height = GetScreenHeight();

        BeginDrawing();

        if (game.player.current == NONE) {
            Rectangle board_length_rec, win_streak_rec;
            screen_end(&game, &board_length_rec, &win_streak_rec);
            screen_listen_input(&game, &board_length_rec, &win_streak_rec);
        } else {
            ClearBackground(TSODINGGRAY);

            game.cell.width = game.window.width / game.length;
            game.cell.height = game.window.height / game.length;

            draw_grid(&game);
            draw_tokens(&game);
            logic_listen_input(&game);
        }

        EndDrawing();
    }

    MemFree(game.board);
    CloseWindow();
}
