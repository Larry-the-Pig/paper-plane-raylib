#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H
#include "global_state.h"

// for future use
typedef struct TitleScreen
{
    int selected_button;
} TitleScreen;

// also for future use
// void title_screen_init();

void title_screen_update(GlobalState* const);

void title_screen_draw(void);

#endif