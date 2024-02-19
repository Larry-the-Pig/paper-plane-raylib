#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdint.h>
#include <stdbool.h>
#include "global_state.h"
#include "screens.h"

typedef struct GlobalState {
    Texture2D* sprite_sheet;
    Texture2D* background;
    GameScreen game_screen;
    float delta_time;
    bool is_screen_changing;
    bool running;
    uint16_t* map;
} GlobalState;

void global_state_init(GlobalState* const, Texture2D*, Texture2D*);

#endif