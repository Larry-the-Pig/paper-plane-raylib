#include "builder_screen.h"
#include "global_state.h"
#include "screens.h"
#include "map.h"
#include "constants.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

void draw_builder_screen(GlobalState *const global_state)
{
    ClearBackground(WHITE);
    draw_map(global_state, 1);


    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mouse_position = Vector2Scale(GetMousePosition(), 1.0f / SPRITE_SIZE);
        printf("%f, %f\n", mouse_position.x, mouse_position.y);
        uint16_t edit = 0x8000;
        edit >>= (int)mouse_position.x;

        global_state->map[(int)mouse_position.y] |= edit;
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Vector2 mouse_position = Vector2Scale(GetMousePosition(), 1.0f / SPRITE_SIZE);
        printf("%f, %f\n", mouse_position.x, mouse_position.y);
        uint16_t edit = 0x8000;
        edit >>= (int)mouse_position.x;

        global_state->map[(int)mouse_position.y] &= ~edit;
    }
}