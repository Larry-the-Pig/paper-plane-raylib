#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <raylib.h>
#include <raymath.h>
#include "global_state.h"
#include "constants.h"
#include "map.h"
#include "screens.h"
#include "gameplay_screen.h"
#include "title_screen.h"
#include "builder_screen.h"

#define FPS 60
#define SPRITE_SIZE 32

#define WINDOW_WIDTH MAP_WIDTH *SPRITE_SIZE
#define WINDOW_HEIGHT 10 * SPRITE_SIZE
#define WINDOW_NAME "Paper Plane"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    SetExitKey(KEY_NULL);

    Texture2D sprite_sheet = LoadTexture("assets/sheet.png");
    Texture2D background = LoadTexture("assets/background.png");

    // Rectangle test = {0.0f, 0.0f, SPRITE_SIZE, SPRITE_SIZE};

    GlobalState *global_state = malloc(sizeof(GlobalState));
    GameplayScreen *gameplay_screen = NULL;
    // TitleScreen *title_screen = NULL;
    BuilderScreen *builder_screen = NULL;
    global_state_init(global_state, &sprite_sheet, &background);

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        global_state->delta_time = GetFrameTime();

        if (global_state->is_screen_changing)
        {
            switch (global_state->game_screen)
            {
            case TITLE:
                // title_screen = malloc(sizeof(TitleScreen));
                // init_title_screen();
                global_state->is_screen_changing = false;
                break;

            case GAMEPLAY:
                gameplay_screen = malloc(sizeof(GameplayScreen));
                init_gameplay_screen(gameplay_screen);
                global_state->is_screen_changing = false;
                break;

            case EDITOR:
                builder_screen = malloc(sizeof(BuilderScreen));
                init_builder_screen(builder_screen);
                global_state->is_screen_changing = false;
                break;

            default:
                break;
            }
        }

        

        

        BeginDrawing();

        switch (global_state->game_screen)
        {
        case TITLE:
            draw_title_screen();
            break;

        case GAMEPLAY:
            draw_gameplay_screen(gameplay_screen, global_state);
            break;

        case EDITOR:
            draw_builder_screen(builder_screen, global_state);
            break;

        default:
            break;
        }

        EndDrawing();

        switch (global_state->game_screen)
        {
        case TITLE:
            update_title_screen(global_state);
            break;

        case GAMEPLAY:
            update_gameplay_screen(gameplay_screen, global_state);
            break;

        case EDITOR:
            update_builder_screen(builder_screen, global_state);
            break;

        default:
            break;
        }
    }

    free(global_state->map);
    global_state->map = NULL;
    free(global_state);
    global_state = NULL;

    return 0;
}
