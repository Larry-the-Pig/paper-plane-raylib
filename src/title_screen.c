#include "title_screen.h"
#include "game_state.h"
#include "screens.h"
#include <raylib.h>

void draw_title_screen(GameState *const game_state)
{
    ClearBackground(WHITE);
    DrawText("Paper Plane", 15, 15, 15, BLACK);
    DrawText("Press Enter", 15, 45, 15, BLACK);

    if (IsKeyPressed(KEY_ENTER)) {
        game_state->game_screen = GAMEPLAY;
    }
}