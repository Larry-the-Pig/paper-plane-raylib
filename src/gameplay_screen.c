#include "constants.h"
#include "paper.h"
#include "map.h"
#include "gameplay_screen.h"
#include <stdio.h>
#include <raymath.h>
#include <stdlib.h>

void init_gameplay_screen(GameplayScreen *const dest)
{
    dest->background_position = 0;
    dest->crash_flag = 0;

    Paper *paper = malloc(sizeof(Paper));
    paper_init(paper);

    dest->paper = paper;
}

void reinit_gameplay_screen(GameplayScreen *const dest)
{
    dest->background_position = 0;
    dest->crash_flag = 0;

    paper_init(dest->paper);
}

void draw_gameplay_screen(GameplayScreen *const gameplay_screen, GlobalState *const global_state)
{
    ClearBackground(WHITE);
    DrawTexture(*global_state->background, 0, 0, WHITE);
    draw_map(global_state, gameplay_screen->background_position);
    DrawTextureRec(*global_state->sprite_sheet, gameplay_screen->paper->sprite_frame, Vector2Scale(gameplay_screen->paper->position, SPRITE_SIZE), WHITE);
}

void update_gameplay_screen(GameplayScreen *const gameplay_screen, GlobalState *const global_state)
{
    if (!gameplay_screen->crash_flag)
    {
        if (IsKeyPressed(KEY_LEFT))
        {
            rotate_left(gameplay_screen->paper);
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            rotate_right(gameplay_screen->paper);
        }

        update_position(gameplay_screen, global_state->delta_time);
        check_collision(gameplay_screen, global_state);
    }

    if (IsKeyPressed(KEY_ENTER) && gameplay_screen->crash_flag)
    {
        reinit_gameplay_screen(gameplay_screen);
    }
}