#include "title_screen.h"
#include "global_state.h"
#include "screens.h"
#include <raylib.h>

void draw_title_screen(GlobalState *const global_state)
{
    ClearBackground(WHITE);
    DrawText("Paper Plane", 15, 15, 36, BLACK);
    DrawText("Press Enter", 15, 15 + 36 + 15, 36, BLACK);

    if (IsKeyPressed(KEY_ENTER)) {
        global_state->game_screen = GAMEPLAY;
    }
}