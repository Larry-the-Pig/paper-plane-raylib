#ifndef BUILDER_SCREEN_H
#define BUILDER_SCREEN_H
#include "global_state.h"

typedef struct BuilderScreen
{
    int scroll_position;
} BuilderScreen;

void init_builder_screen();

void update_builder_screen();

void draw_builder_screen(GlobalState* const global_state);

#endif