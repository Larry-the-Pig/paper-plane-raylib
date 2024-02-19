#include "title_screen.h"
#include "global_state.h"
#include "screens.h"
#include "map.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

void title_screen_draw(TitleScreen *const title_screen, GlobalState *const game_state)
{
    ClearBackground(SKYBLUE);
    map_draw(game_state, title_screen->background_position);
    DrawRectangle(0, 0, GetRenderWidth(), GetRenderHeight(), (Color){0, 0, 0, 200});
    DrawText("Paper Plane", 36, 36, 36, WHITE);
    switch (title_screen->selected_button)
    {
    case 0:
        DrawText("Play", 36, 36 * 2, 36, WHITE);
        DrawText("Edit", 36, 36 * 3, 36, GRAY);
        DrawText("Quit", 36, 36 * 4, 36, GRAY);
        break;

    case 1:
        DrawText("Play", 36, 36 * 2, 36, GRAY);
        DrawText("Edit", 36, 36 * 3, 36, WHITE);
        DrawText("Quit", 36, 36 * 4, 36, GRAY);
        break;

    case 2:
        DrawText("Play", 36, 36 * 2, 36, GRAY);
        DrawText("Edit", 36, 36 * 3, 36, GRAY);
        DrawText("Quit", 36, 36 * 4, 36, WHITE);
        break;

    default:
        break;
    }
}

void title_screen_update(TitleScreen *const title_screen, GlobalState *const game_state)
{
    if (IsKeyPressed(KEY_DOWN) && title_screen->selected_button < MAX_BUTTON)
    {
        title_screen->selected_button++;
    }

    if (IsKeyPressed(KEY_UP) && title_screen->selected_button > MIN_BUTTON)
    {
        title_screen->selected_button--;
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        if (title_screen->selected_button == 0)
            game_state->game_screen = GAMEPLAY;
        game_state->is_screen_changing = true;

        if (title_screen->selected_button == 1)
            game_state->game_screen = EDITOR;
        game_state->is_screen_changing = true;

        if (title_screen->selected_button == 2)
            game_state->running = false;
    }

    title_screen->background_position += game_state->delta_time;
}

void title_screen_init(TitleScreen *const dest)
{
    dest->background_position = 0.0f;
    dest->selected_button = 0;
}