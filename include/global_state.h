#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdint.h>
#include "global_state.h"
#include "screens.h"

typedef struct GlobalState {
    Texture2D* sprite_sheet;
    Texture2D* background;
    GameScreen game_screen;
    float delta_time;
    uint16_t* map;
} GlobalState;

void global_state_init(GlobalState* const global_state, Texture2D* sprite_sheet, Texture2D *background);

#endif