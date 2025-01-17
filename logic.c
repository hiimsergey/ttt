#include <raylib.h>
#include "game.h"

bool draw_check(Game *game) {
    for (int x = 0; x < game->length; ++x)
        for (int y = 0; y < game->length; ++y)
            if (game->board[x * game->length + y] == NONE) return false;

    game->player.won = DRAW;
    game->player.current = NONE;

    return true;
}

bool vertical_check(const Game *game, const int x) {
    int streak = 0;

    for (int y = 0; y < game->length; ++y) {
        if (game->board[x * game->length + y] == game->player.current) ++streak;
        else streak = 0;
        if (streak == game->streak) return true;
    }

    return false;
}

bool horizontal_check(const Game *game, const int y) {
    int streak = 0;

    for (int x = 0; x < game->length; ++x) {
        if (game->board[x * game->length + y] == game->player.current) ++streak;
        else streak = 0;
        if (streak == game->streak) return true;
    }

    return false;
}

bool primary_diagonal_check(const Game *game, int x, int y) {
    int streak = 0;

    const int i_sum = x + y;
    if (i_sum >= game->length) {
        x = game->length - 1;
        y = i_sum - game->length + 1;
    } else {
        x = i_sum;
        y = 0;
    }

    for (; x >= 0 && y < game->length; --x, ++y) {
        if (game->board[x * game->length + y] == game->player.current) ++streak;
        else streak = 0;
        if (streak == game->streak) return true;
    }

    return false;
}

bool secondary_diagonal_check(const Game *game, int x, int y) {
    int streak = 0;
    const int subtract = x < y ? x : y;

    for (
        x -= subtract, y -= subtract;
        x < game->length && y < game->length;
        ++x, ++y
    ) {
        if (game->board[x * game->length + y] == game->player.current) ++streak;
        else streak = 0;
        if (streak == game->streak) return true;
    }

    return false;
}

void clear_board(Game *game) {
    for (int i = 0; i < game->length * game->length; ++i) game->board[i] = NONE;
}

bool current_player_won(Game *game, const int x, const int y) {
    if (
        vertical_check(game, x)
        || horizontal_check(game, y)
        || primary_diagonal_check(game, x, y)
        || secondary_diagonal_check(game, x, y)
    ) {
        game->player.won = game->player.current;
        game->player.current = NONE;
        clear_board(game);
        return true;
    }

    return draw_check(game);
}

void logic_listen_input(Game *game) {
    if (IsKeyPressed(KEY_Q)) {
        game->player.won = NONE;
        game->player.current = NONE;
        clear_board(game);
        return;
    }

    if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return;
    const int clicked_x = GetMouseX() / game->cell.width;
    const int clicked_y = GetMouseY() / game->cell.height;

    if (game->board[clicked_x * game->length + clicked_y] == NONE) {
        game->board[clicked_x * game->length + clicked_y] = game->player.current;

        if (!current_player_won(game, clicked_x, clicked_y))
            game->player.current = X + O - game->player.current;
    }
}
