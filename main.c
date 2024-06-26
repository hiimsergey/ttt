#include <raylib.h>
#include "game.h"
#include "draw.h"
#include "logic.h"
#include "screen.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(512, 512, "ttt v0.0.1");
    SetTargetFPS(30);

    Game game = {
        .board = MemAlloc(sizeof(enum state *) * 3),
        .player.current = NONE,
        .player.won = NONE,
        .length = 3,
        .streak = 3
    };

    while (!WindowShouldClose()) {
        game.window.width = GetScreenWidth();
        game.window.height = GetScreenHeight();

        BeginDrawing();

        if (game.player.current == NONE) {
            Rectangle board_length_rec, win_streak_rec;
            screen_end(&game, &board_length_rec, &win_streak_rec);
            screen_listen_input(&game, &board_length_rec, &win_streak_rec);
        } else {
            ClearBackground(RAYWHITE);

            game.cell.width = game.window.width / game.length;
            game.cell.height = game.window.height / game.length;

            draw_grid(&game);
            draw_tokens(&game);
            logic_listen_input(&game);
        }

        EndDrawing();
    }

    for (int x = 0; x < game.length; ++x) MemFree(game.board[x]);
    MemFree(game.board);

    CloseWindow();
}
