#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <raylib.h>
#include <raymath.h>
#include "global_state.h"
#include "constants.h"
#include "map.h"
#include "screens.h"
#include "gameplay_screen.h"

#define FPS 60
#define SPRITE_SIZE 32

#define WINDOW_WIDTH MAP_WIDTH *SPRITE_SIZE
#define WINDOW_HEIGHT 10 * SPRITE_SIZE
#define WINDOW_NAME "Paper Plane"

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    Texture2D sprite_sheet = LoadTexture("assets/sheet.png");
    Texture2D background = LoadTexture("assets/background.png");

    // Rectangle test = {0.0f, 0.0f, SPRITE_SIZE, SPRITE_SIZE};

    GlobalState *global_state = malloc(sizeof(GlobalState));
    GameplayScreen *gameplay_screen = malloc(sizeof(GameplayScreen));
    global_state_init(global_state, &sprite_sheet, &background);
    init_gameplay_screen(gameplay_screen);

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        global_state->delta_time = GetFrameTime();

        update_gameplay_screen(gameplay_screen, global_state);

        BeginDrawing();

        draw_gameplay_screen(gameplay_screen, global_state);

        EndDrawing();
    }

    free(global_state->map);
    global_state->map = NULL;
    free(global_state);
    global_state = NULL;

    free(gameplay_screen->paper);
    gameplay_screen->paper = NULL;
    free(gameplay_screen);
    gameplay_screen = NULL;

    return 0;
}
