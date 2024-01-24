#include "paper.h"
#include "constants.h"
#include <stdlib.h>

void update_sprite_rotation(Paper* dest) {
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

void rotate_left(Paper* dest) {
    if(dest->rotation > PAPER_MIN_ROTATION) dest->rotation--;

    update_sprite_rotation(dest);
}

void rotate_right(Paper* dest) {
    if(dest->rotation < PAPER_MAX_ROTATION) dest->rotation++;

    update_sprite_rotation(dest);
}

void paper_init(Paper* dest) {
    dest->position.x = PAPER_START_X;
    dest->position.y = PAPER_START_Y;
    dest->sprite_frame.x = 0.0f;
    dest->sprite_frame.y = 0.0f;
    dest->sprite_frame.width = SPRITE_SIZE;
    dest->sprite_frame.height = SPRITE_SIZE;
    dest->rotation = 0;

    update_sprite_rotation(dest);
}

int get_gravity_from_rotation(int rotation) {
    return -abs(rotation) + BASE_GRAVITY;
}