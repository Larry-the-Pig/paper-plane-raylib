#ifndef MAP_H
#define MAP_H
#include "types.h"
#include "global_state.h"

#define MAP_WIDTH 16
#define MAP_HEIGHT 119

void map_init(uint16_t*);

void map_draw(GlobalState* const, float);

#endif