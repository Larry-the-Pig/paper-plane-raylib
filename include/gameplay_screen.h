#ifndef GAMEPLAY_SCREEN_H
#define GAMEPLAY_SCREEN_H
#include "global_state.h"
#include "paper.h"

typedef struct GameplayScreen
{
    Paper *paper;
    int crash_flag;
    float background_position;
} GameplayScreen;

void init_gameplay_screen(GameplayScreen *const dest);

void reinit_gameplay_screen(GameplayScreen *const dest);

void draw_gameplay_screen(GameplayScreen *const gameplay_screen, GlobalState *const global_state);

void update_gameplay_screen(GameplayScreen *const gameplay_screen, GlobalState *const global_state);

void check_collision(GameplayScreen* const gameplay_state, GlobalState* const global_state);

void update_position(GameplayScreen* const dest, float delta_time);

#endif