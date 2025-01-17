#include <math.h>
#include <raylib.h>
#include "game.h"

void draw_grid(const Game *game) {
    const Color color = game->player.current == X ? RED : BLUE;

    for (int i = 1; i < game->length; ++i) {
        // Vertical lines
        DrawRectangle(
            (i - .05) * game->cell.width, .1 * game->cell.height,
            .1 * game->cell.width, game->window.height - .2 * game->cell.height,
            color
        );

        // Horizontal lines
        DrawRectangle(
            .1 * game->cell.width, (i - .05) * game->cell.height,
            game->window.width - .2 * game->cell.width, .1 * game->cell.height,
            color
        );
    }
}

void draw_x(const Game *game, const int x, const int y) {
    const int inner_cell_length = game->cell.height * .6;
    const int stroke_height = inner_cell_length * .25;
    const int stroke_width = sqrt(2) * inner_cell_length - stroke_height;

    const Rectangle rec = {
        (x + .5) * game->cell.width,
        (y + .5) * game->cell.height,
        stroke_width, stroke_height
    };

    DrawRectanglePro(
        rec,
        (Vector2) { stroke_width * .5, stroke_height * .5 },
        45,
        RED
    );
    DrawRectanglePro(
        rec,
        (Vector2) { stroke_width * .5, stroke_height * .5 },
        -45,
        RED
    );
}

void draw_o(const Game *game, const int x, const int y) {
    const int inner_cell_half = game->cell.height * .3;

    DrawRing(
        (Vector2) {
            (x + .5) * game->cell.width,
            (y + .5) * game->cell.height
        },
        inner_cell_half * .5, inner_cell_half,
        0, 360, 360,
        BLUE
    );
}

void draw_tokens(const Game *game) {
    for (int x = 0; x < game->length; ++x)
        for (int y = 0; y < game->length; ++y)
            switch (game->board[x * game->length + y]) {
                case X:
                    draw_x(game, x, y);
                    break;
                case O:
                    draw_o(game, x, y);
                    break;
                default: break;
            }
}
