#ifndef BUILDER_SCREEN_H
#define BUILDER_SCREEN_H
#include "global_state.h"

typedef struct BuilderScreen
{
    float scroll_position;
} BuilderScreen;

void init_builder_screen(BuilderScreen *const builder_screen);

void update_builder_screen(BuilderScreen *const builder_screen, GlobalState *const global_state);

void draw_builder_screen(BuilderScreen *const builder_screen, GlobalState *const global_state);

#endif