#include "paper.h"
#include "constants.h"
#include "gameplay_screen.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

void paper_update_sprite_rotation(Paper* dest) {
    switch(dest->rotation) {
    case -3:
        dest->sprite_frame.x = 0 * SPRITE_SIZE;
        break;
    case -2:
        dest->sprite_frame.x = 1 * SPRITE_SIZE;
        break;
    case -1:
        dest->sprite_frame.x = 2 * SPRITE_SIZE;
        break;
    case 0:
        dest->sprite_frame.x = 3 * SPRITE_SIZE;
        break;
    case 1:
        dest->sprite_frame.x = 4 * SPRITE_SIZE;
        break;
    case 2:
        dest->sprite_frame.x = 5 * SPRITE_SIZE;
        break;
    case 3:
        dest->sprite_frame.x = 6 * SPRITE_SIZE;
        break;

    default:
        break;
    }
}

void paper_rotate_left(Paper* dest) {
    if(dest->rotation > PAPER_MIN_ROTATION) dest->rotation--;

    paper_update_sprite_rotation(dest);
}

void paper_rotate_right(Paper* dest) {
    if(dest->rotation < PAPER_MAX_ROTATION) dest->rotation++;

    paper_update_sprite_rotation(dest);
}

void paper_init(Paper* dest) {
    dest->position.x = PAPER_START_X;
    dest->position.y = PAPER_START_Y;
    dest->sprite_frame.x = 0.0f;
    dest->sprite_frame.y = 0.0f;
    dest->sprite_frame.width = SPRITE_SIZE;
    dest->sprite_frame.height = SPRITE_SIZE;
    dest->rotation = 0;

    paper_update_sprite_rotation(dest);
}

int get_gravity_from_rotation(int rotation) {
    return -abs(rotation) + BASE_GRAVITY;
}

void check_collision(GameplayScreen* const gameplay_state, GlobalState* const global_state)
{
    /*
        to make collision detection easier,
        convert the u_int16_t to an array of
        u_int8_t's
    */
    uint8_t currentRow[sizeof(uint16_t) * 8];
    // check the position right in front of player
    uint16_t mapCopy = global_state->map[(int)gameplay_state->background_position + PAPER_START_Y + 1];
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

    if (gameplay_state->paper->position.x < 0)
    {
        gameplay_state->crash_flag = 1;
        return;
    }

    if (gameplay_state->paper->position.x > MAP_WIDTH - 1)
    {
        gameplay_state->crash_flag = 1;
        return;
    }

    // TODO: this collision code barely works, needs a refactor
    if (currentRow[(unsigned int)(gameplay_state->paper->position.x + 0.375)] ||
        currentRow[(unsigned int)(gameplay_state->paper->position.x + 0.625)])
    {
        gameplay_state->crash_flag = 1;
    }
}

void update_position(GameplayScreen* const dest, float delta_time)
{
    dest->paper->position.x += (float)dest->paper->rotation * ROTATION_MULTIPLIER * delta_time;
    dest->background_position += (float)get_gravity_from_rotation(dest->paper->rotation) * delta_time;
}