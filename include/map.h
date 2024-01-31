#ifndef MAP_H
#define MAP_H
#include <stdint.h>
#include "global_state.h"

#define MAP_WIDTH 16
#define MAP_HEIGHT 119

void init_map(uint16_t* map);

void draw_map(GlobalState* const global_state, float background_position);

#endif