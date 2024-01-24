#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdlib.h>
#include "game_state.h"
#include "paper.h"

typedef struct GameState {
    Texture2D* sprite_sheet;
    Paper* paper;
    uint16_t* map;
    int crash_flag;
    float background_position;
} GameState;

void game_state_init(GameState* const game_state, Texture2D* sprite_sheet);

void game_state_reinit(GameState* const game_state);

void check_collision(GameState* const game_state);

void update_position(GameState* dest, float delta_time);

#endif