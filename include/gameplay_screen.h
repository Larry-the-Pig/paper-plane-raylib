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

void gameplay_screen_init(GameplayScreen *const);

void gameplay_screen_reinit(GameplayScreen *const);

void gameplay_screen_draw(GameplayScreen *const, GlobalState *const);

void gameplay_screen_update(GameplayScreen *const, GlobalState *const);

void check_collision(GameplayScreen* const, GlobalState* const);

void update_position(GameplayScreen* const, float);

#endif