#include "title_screen.h"
#include "global_state.h"
#include "screens.h"
#include <raylib.h>
#include "types.h"
#include <stdio.h>

void title_screen_draw(void)
{
    ClearBackground(WHITE);
    DrawText("Paper Plane", 15, 15, 36, BLACK);
    DrawText("Press Enter", 15, 15 + 36 + 15, 36, BLACK);
}

void title_screen_update(GlobalState *const dest)
{
    if (IsKeyPressed(KEY_ENTER)) {
        dest->game_screen = GAMEPLAY;
        dest->is_screen_changing = true;
    }

    if (IsKeyPressed(KEY_B)) {
        dest->game_screen = EDITOR;
        dest->is_screen_changing = true;
    }
}