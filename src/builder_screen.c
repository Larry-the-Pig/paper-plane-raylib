#include "builder_screen.h"
#include "global_state.h"
#include "screens.h"
#include "map.h"
#include "constants.h"
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdbool.h>

#define SCROLL_SPEED 0.5

void builder_screen_update(BuilderScreen *const builder_screen, GlobalState *const global_state)
{
    builder_screen->scroll_position -= (GetMouseWheelMove() * SCROLL_SPEED);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse_position = Vector2Scale(GetMousePosition(), 1.0f / SPRITE_SIZE);
        uint16_t edit = 0x8000;
        edit >>= (int)mouse_position.x;

        global_state->map[(int)(mouse_position.y + builder_screen->scroll_position)] |= edit;
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        Vector2 mouse_position = Vector2Scale(GetMousePosition(), 1.0f / SPRITE_SIZE);
        uint16_t edit = 0x8000;
        edit >>= (int)mouse_position.x;

        global_state->map[(int)(mouse_position.y + builder_screen->scroll_position)] &= ~edit;
    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        free(builder_screen);

        global_state->is_screen_changing = true;
        global_state->game_screen = TITLE;
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