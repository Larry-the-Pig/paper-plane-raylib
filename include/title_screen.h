#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H
#include "global_state.h"

// for future use
typedef struct TitleScreen
{
    int selected_button;
} TitleScreen;

// also for future use
// void init_title_screen(void);

void update_title_screen(GlobalState* const global_state);

void draw_title_screen(void);

#endif