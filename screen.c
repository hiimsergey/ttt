#include <raylib.h>
#include "game.h"

void screen_end(
    const Game *game,
    Rectangle *board_length_rec,
    Rectangle *win_streak_rec
) {
    Color background;
    const char *message;

    switch (game->player.won) {
        case X:
            background = RED;
            message = "X won";
            break;
        case O:
            background = BLUE;
            message = "O won";
            break;
        case DRAW:
            background = GRAY;
            message = "Draw";
            break;
        default:
            background = LIME;
            message = "ttt";
            break;
    }

    ClearBackground(background);

    #define TEXT_X               game->window.width * .1
    #define SETTINGS_NUM_Y       game->window.height * .55
    #define SETTINGS_NUM_HEIGHT  game->window.height * .2
    #define SETTINGS_DESC_Y      game->window.height * .75
    #define SETTINGS_DESC_HEIGHT game->window.height * .05
    #define SETTINGS_RECT_LENGTH game->window.width * .4
    #define WIN_STREAK_X         game->window.width * .5

/* ------------- TOP TEXT ----------------------------------------------------*/

    DrawText(
        message,
        TEXT_X, game->window.height * .1,
        game->window.height * .2,
        RAYWHITE
    );
    DrawText(
        "Press Enter to start",
        TEXT_X, game->window.height * .3,
        game->window.height * .075,
        RAYWHITE
    );
    DrawText(
        "Scroll the numbers to change them",
        TEXT_X, game->window.height * .45,
        game->window.height * .04,
        RAYWHITE
    );

/* ------------- BOARD LENGTH SETTINGS ---------------------------------------*/
    *board_length_rec = (Rectangle) {
        TEXT_X, SETTINGS_NUM_Y,
        SETTINGS_RECT_LENGTH, SETTINGS_RECT_LENGTH
    };
    DrawRectangleRec(*board_length_rec, background);
    
    DrawText(
        TextFormat("%d", game->length),
        TEXT_X, SETTINGS_NUM_Y,
        SETTINGS_NUM_HEIGHT,
        RAYWHITE
    );
    DrawText(
        "board length",
        TEXT_X, SETTINGS_DESC_Y,
        SETTINGS_DESC_HEIGHT,
        RAYWHITE
    );

/* ------------- WIN STREAK SETTINGS -----------------------------------------*/
    *win_streak_rec = (Rectangle) {
        WIN_STREAK_X, SETTINGS_NUM_Y,
        SETTINGS_RECT_LENGTH, SETTINGS_RECT_LENGTH
    };
    DrawRectangleRec(*win_streak_rec, background);

    DrawText(
        TextFormat("%d", game->streak),
        WIN_STREAK_X, SETTINGS_NUM_Y,
        SETTINGS_NUM_HEIGHT,
        RAYWHITE
    );
    DrawText(
        "streak to win",
        WIN_STREAK_X, SETTINGS_DESC_Y,
        SETTINGS_DESC_HEIGHT,
        RAYWHITE
    );

/* ------------- CREDITS I GUESS ---------------------------------------------*/
    DrawText(
        "v0.1.1    GPL-3.0    github.com/hiimsergey/ttt",
        TEXT_X, game->window.height * .9,
        game->window.height * .039,
        LIGHTGRAY
    );
}

void screen_listen_input(
    Game *game,
    const Rectangle *board_length_rec,
    const Rectangle *win_streak_rec
) {
    if (IsKeyPressed(KEY_ENTER)) {
        game->player.current = X;
        game->player.won = NONE;

        game->board = MemRealloc(
            game->board,
            sizeof(enum state *) * game->length
        );

        for (int x = 0; x < game->length; ++x) {
            game->board[x] = MemAlloc(sizeof(enum state) * game->length);
            for (int y = 0; y < game->length; ++y) game->board[x][y] = NONE;
        }
    }

    if (IsKeyPressed(KEY_UP)) ++game->length;
    if (IsKeyPressed(KEY_DOWN)) --game->length;
    if (IsKeyPressed(KEY_RIGHT)) ++game->streak;
    if (IsKeyPressed(KEY_LEFT)) --game->streak;

    const Vector2 mouse = GetMousePosition();
    const int wheel = GetMouseWheelMove();
    if (!wheel) return;

    if (CheckCollisionPointRec(mouse, *board_length_rec))
        game->length += wheel;
    if (game->length < 2) game->length = 2;

    if (CheckCollisionPointRec(mouse, *win_streak_rec))
        game->streak += wheel;
    if (game->streak < 2) game->streak = 2;
    if (game->streak > game->length) game->streak = game->length;
}
