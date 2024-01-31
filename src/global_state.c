#include <stdlib.h>
#include <stdint.h>
#include "global_state.h"
#include "paper.h"
#include "map.h"
#include "screens.h"

void global_state_init(GlobalState *const global_state, Texture2D *sprite_sheet, Texture2D *background)
{
    global_state->game_screen = GAMEPLAY;
    global_state->sprite_sheet = sprite_sheet;
    global_state->background = background;
    global_state->delta_time = 0.0f;

    uint16_t *map = malloc(sizeof(uint16_t) * MAP_HEIGHT);
    init_map(map);

    global_state->map = map;
}