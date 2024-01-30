#include <stdlib.h>
#include <stdint.h>
#include "game_state.h"
#include "paper.h"
#include "map.h"
#include "screens.h"

void game_state_init(GameState* const game_state, Texture2D *sprite_sheet)
{
    game_state->crash_flag = 0;
    game_state->game_screen = TITLE;
    game_state->background_position = 0;
    game_state->sprite_sheet = sprite_sheet;

    Paper *paper = malloc(sizeof(Paper));
    paper_init(paper);

    uint16_t *map = malloc(sizeof(uint16_t) * MAP_HEIGHT);
    init_map(map);

    game_state->paper = paper;
    game_state->map = map;
}

void game_state_reinit(GameState* const game_state)
{
    game_state->crash_flag = 0;
    game_state->background_position = 0;

    paper_init(game_state->paper);
}

void check_collision(GameState* const game_state)
{
    /*
        to make collision detection easier,
        convert the u_int16_t to an array of
        u_int8_t's
    */
    uint8_t currentRow[sizeof(uint16_t) * 8];
    // check the position right in front of player
    uint16_t mapCopy = game_state->map[(int)game_state->background_position + PAPER_START_Y + 1];
    for (unsigned int j = 0; j < sizeof(uint16_t) * 8; j++)
    {
        if (mapCopy & 0x8000)
        {
            currentRow[j] = 1;
        }
        else
        {
            currentRow[j] = 0;
        }

        mapCopy <<= 1;
    }

    if (game_state->paper->position.x < 0)
    {
        game_state->crash_flag = 1;
        return;
    }

    if (game_state->paper->position.x > MAP_WIDTH - 1)
    {
        game_state->crash_flag = 1;
        return;
    }

    // TODO: this collision code barely works, needs a refactor
    if (currentRow[(unsigned int)(game_state->paper->position.x + 0.375)] ||
        currentRow[(unsigned int)(game_state->paper->position.x + 0.625)])
    {
        game_state->crash_flag = 1;
    }
}

void update_position(GameState* const dest, float delta_time)
{
    dest->paper->position.x += (float)dest->paper->rotation * ROTATION_MULTIPLIER * delta_time;
    dest->background_position += (float)get_gravity_from_rotation(dest->paper->rotation) * delta_time;
}