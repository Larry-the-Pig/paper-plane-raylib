#include "builder_screen.h"
#include "global_state.h"
#include "screens.h"
#include "map.h"
#include "constants.h"
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define SCROLL_SPEED 0.5

void builder_screen_update(BuilderScreen *const builder_screen, GlobalState *const global_state)
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        free(builder_screen);

        global_state->is_screen_changing = true;
        global_state->game_screen = TITLE;
        return;
    }

    builder_screen->scroll_position -= (GetMouseWheelMove() * SCROLL_SPEED);

    Vector2 mouse_position = {0.0f, 0.0f};
    uint16_t edit = 0x8000;
    int offset = 0;

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        mouse_position = Vector2Scale(GetMousePosition(), 1.0f / SPRITE_SIZE);
        edit >>= (int)mouse_position.x;
        offset = (int)(mouse_position.y + builder_screen->scroll_position);

        if (offset > MAP_HEIGHT || offset < 0)
        {
            return;
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        global_state->map[offset] |= edit;
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        global_state->map[offset] &= ~edit;
    }
}

void builder_screen_draw(BuilderScreen *const builder_screen, GlobalState *const global_state)
{
    ClearBackground(WHITE);
    DrawTexture(*global_state->background, 0, 0, WHITE);
    map_draw(global_state, builder_screen->scroll_position);
}

void builder_screen_init(BuilderScreen *const builder_screen)
{
    builder_screen->scroll_position = 0.0f;
}