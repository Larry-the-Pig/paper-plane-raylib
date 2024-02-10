#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include "global_state.h"
#include "constants.h"
#include "map.h"
#include "screens.h"
#include "gameplay_screen.h"
#include "title_screen.h"
#include "builder_screen.h"

#define FPS 60

#define WINDOW_WIDTH MAP_WIDTH *SPRITE_SIZE
#define WINDOW_HEIGHT 10 * SPRITE_SIZE
#define WINDOW_NAME "Paper Plane"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2, WINDOW_NAME);
    SetExitKey(KEY_NULL);

    Camera2D cam = {0};
    cam.zoom = GetScreenWidth() / WINDOW_WIDTH;

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
                // (\w+)_title_screen();
                global_state->is_screen_changing = false;
                break;

            case GAMEPLAY:
                gameplay_screen = malloc(sizeof(GameplayScreen));
                gameplay_screen_init(gameplay_screen);
                global_state->is_screen_changing = false;
                break;

            case EDITOR:
                builder_screen = malloc(sizeof(BuilderScreen));
                builder_screen_init(builder_screen);
                global_state->is_screen_changing = false;
                break;

            default:
                break;
            }
        }

        BeginDrawing();

        BeginMode2D(cam);

        DrawLine(0, 100, WINDOW_WIDTH, 100, RED);
        DrawText(TextFormat("%0.0f units", WINDOW_WIDTH), WINDOW_WIDTH / 2, 100, 20, MAROON);

        DrawCircle(200, 200, 50, PURPLE);

        Vector2 worldspaceCursor = GetScreenToWorld2D(GetMousePosition(), cam);
        DrawText(TextFormat("World Space X%0.0f Y%0.0f", worldspaceCursor.x, worldspaceCursor.y), worldspaceCursor.x, worldspaceCursor.y - 10, 10, YELLOW);

        EndMode2D();

        switch (global_state->game_screen)
        {
        case TITLE:
            title_screen_draw();
            break;

        case GAMEPLAY:
            gameplay_screen_draw(gameplay_screen, global_state);
            break;

        case EDITOR:
            builder_screen_draw(builder_screen, global_state);
            break;

        default:
            break;
        }

        EndDrawing();

        switch (global_state->game_screen)
        {
        case TITLE:
            title_screen_update(global_state);
            break;

        case GAMEPLAY:
            gameplay_screen_update(gameplay_screen, global_state);
            break;

        case EDITOR:
            builder_screen_update(builder_screen, global_state);
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
