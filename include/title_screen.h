#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H
#include "global_state.h"

#define MIN_BUTTON 0
#define MAX_BUTTON 2

typedef struct TitleScreen
{
    int selected_button;
    float background_position;
} TitleScreen;

void title_screen_update(TitleScreen* const, GlobalState* const);

void title_screen_draw(TitleScreen* const, GlobalState *const);

void title_screen_init(TitleScreen* const);

#endif