#ifndef BUILDER_SCREEN_H
#define BUILDER_SCREEN_H
#include "global_state.h"

typedef struct BuilderScreen
{
    float scroll_position;
} BuilderScreen;

void builder_screen_init(BuilderScreen *const);

void builder_screen_update(BuilderScreen *const, GlobalState *const);

void builder_screen_draw(BuilderScreen *const, GlobalState *const);

#endif