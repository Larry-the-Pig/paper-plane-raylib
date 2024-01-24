#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <raylib.h>
#include <raymath.h>
#include "game_state.h"
#include "paper.h"
#include "constants.h"
#include "map.h"

#define FPS 60
#define PIXEL_UPSCALE 4

#define WINDOW_WIDTH MAP_WIDTH * SPRITE_SIZE
#define WINDOW_HEIGHT 10 * SPRITE_SIZE
#define WINDOW_NAME "Paper Plane"

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    Texture2D sprite_sheet = LoadTexture("assets/sheet1.png");

    // Rectangle test = {0.0f, 0.0f, SPRITE_SIZE, SPRITE_SIZE};

    GameState *game_state = malloc(sizeof(GameState));
    game_state_init(game_state, &sprite_sheet);

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if (IsKeyPressed(KEY_LEFT))
        {
            rotate_left(game_state->paper);
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            rotate_right(game_state->paper);
        }

        if (IsKeyPressed(KEY_ENTER) && game_state->crash_flag)
        {
            game_state_reinit(game_state);
        }

        if (!game_state->crash_flag)
        {
            update_position(game_state, deltaTime);
            check_collision(game_state);
        }

        BeginDrawing();

        ClearBackground(WHITE);
        draw_map(game_state);
        DrawTextureRec(sprite_sheet, game_state->paper->sprite_frame, Vector2Scale(game_state->paper->position, SPRITE_SIZE), WHITE);

        EndDrawing();
    }

    free(game_state->paper);
    game_state->paper = NULL;
    free(game_state->map);
    game_state->map = NULL;
    free(game_state);
    game_state = NULL;

    return 0;
}
