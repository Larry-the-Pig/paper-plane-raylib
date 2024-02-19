#include "constants.h"
#include "paper.h"
#include "map.h"
#include "gameplay_screen.h"
#include <stdio.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdbool.h>

void gameplay_screen_init(GameplayScreen *const dest)
{
    dest->background_position = 0.0f;
    dest->crash_flag = 0;

    Paper *paper = malloc(sizeof(Paper));
    paper_init(paper);

    dest->paper = paper;
}

void gameplay_screen_reinit(GameplayScreen *const dest)
{
    dest->background_position = 0;
    dest->crash_flag = 0;

    paper_init(dest->paper);
}

void gameplay_screen_draw(GameplayScreen *const gameplay_screen, GlobalState *const global_state)
{
    ClearBackground(SKYBLUE);
    //DrawTexture(*global_state->background, 0, 0, WHITE);
    map_draw(global_state, gameplay_screen->background_position);
    DrawTextureRec(*global_state->sprite_sheet, gameplay_screen->paper->sprite_frame, Vector2Scale(gameplay_screen->paper->position, SPRITE_SIZE), WHITE);
}

void gameplay_screen_update(GameplayScreen *const gameplay_screen, GlobalState *const global_state)
{
    if (!gameplay_screen->crash_flag)
    {
        if (IsKeyPressed(KEY_LEFT))
        {
            paper_rotate_left(gameplay_screen->paper);
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            paper_rotate_right(gameplay_screen->paper);
        }

        update_position(gameplay_screen, global_state->delta_time);
        check_collision(gameplay_screen, global_state);
    }

    if (IsKeyPressed(KEY_ENTER) && gameplay_screen->crash_flag)
    {
        gameplay_screen_reinit(gameplay_screen);
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
        free(gameplay_screen->paper);
        gameplay_screen->paper = NULL;

        free(gameplay_screen);

        global_state->is_screen_changing = true;
        global_state->game_screen = TITLE;
    }
}