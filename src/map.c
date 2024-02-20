#include <stdint.h>
#include "global_state.h"
#include "map.h"
#include "constants.h"
#include "binary_const.h"

void map_init(uint16_t *map)
{
    /*
        this is all the map data same as
        the map from https://ticalc.org/archives/files/fileinfo/341/34139.html
        1: 8x8 tile exists on an 8x8 grid
        0: no 8x8 tile
    */

    map[0] = B(1111111001111111);
    map[1] = B(1111110000111111);
    map[2] = B(1111000000001111);
    map[3] = B(0000000000000000);
    map[4] = B(0000000000000000);
    map[5] = B(0000000000011111);
    map[6] = B(0000000000000000);
    map[7] = B(0000000000000000);
    map[8] = B(1111111100000000);
    map[9] = B(0000000000000000);
    map[10] = B(0000000000000000);
    map[11] = B(0000000000000000);
    map[12] = B(1111000000111111);
    map[13] = B(0000000000000000);
    map[14] = B(0000000000000000);
    map[15] = B(0000000011110000);
    map[16] = B(0000000000000000);
    map[17] = B(0000000000110000);
    map[18] = B(0000000000000000);
    map[19] = B(0000000000000000);
    map[20] = B(1111111110000000);
    map[21] = B(0000000000000111);
    map[22] = B(1111000000000000);
    map[23] = B(0000000000000000);
    map[24] = B(0000000000000000);
    map[25] = B(0000000000000000);
    map[26] = B(0000000011110000);
    map[27] = B(0000000000000000);
    map[28] = B(0000000000110000);
    map[29] = B(0000000000000000);
    map[30] = B(1111110000000111);
    map[31] = B(0000000000000000);
    map[32] = B(0000000011111111);
    map[33] = B(0000000000000000);
    map[34] = B(0000000000000000);
    map[35] = B(0000000111110000);
    map[36] = B(0000000000000000);
    map[37] = B(0000000000000000);
    map[38] = B(0000000011000000);
    map[39] = B(1110000000000111);
    map[40] = B(1110000000000111);
    map[41] = B(0000000000000000);
    map[42] = B(1111111111000000);
    map[43] = B(0000000000000000);
    map[44] = B(1111100000000000);
    map[45] = B(0000000000111111);
    map[46] = B(0000000000000000);
    map[47] = B(0000001111110000);
    map[48] = B(0000000000000000);
    map[49] = B(0000000000000000);
    map[50] = B(0000000000000000);
    map[51] = B(0000000000000000);
    map[52] = B(0001111100001111);
    map[53] = B(0000000000000000);
    map[54] = B(0000000000000000);
    map[55] = B(0000001111110000);
    map[56] = B(0000000000000000);
    map[57] = B(0000000000000000);
    map[58] = B(1111110000000000);
    map[59] = B(0000000000001111);
    map[60] = B(0000000000000000);
    map[61] = B(0000011110000000);
    map[62] = B(0000000000000000);
    map[63] = B(0000000001110000);
    map[64] = B(0000000000000000);
    map[65] = B(0000111111000000);
    map[66] = B(0000000000000000);
    map[67] = B(0000000001111111);
    map[68] = B(0000000000000000);
    map[69] = B(0000011000000000);
    map[70] = B(0000000000000000);
    map[71] = B(0000001111000000);
    map[72] = B(0000000000000000);
    map[73] = B(0000000000110000);
    map[74] = B(0000111100000000);
    map[75] = B(0000000000000000);
    map[76] = B(0001100000111111);
    map[77] = B(0000000000000000);
    map[78] = B(0000000000000000);
    map[79] = B(1111111111000000);
    map[80] = B(0000000000000000);
    map[81] = B(0000000011110000);
    map[82] = B(0000000000000000);
    map[83] = B(0001111001100000);
    map[84] = B(0000000000000000);
    map[85] = B(0000000000000000);
    map[86] = B(0000110011000111);
    map[87] = B(0000000000011111);
    map[88] = B(0000000000000000);
    map[89] = B(1111000000001111);
    map[90] = B(0000000001100000);
    map[91] = B(1111000000000000);
    map[92] = B(0000000110000000);
    map[93] = B(0000110000110000);
    map[94] = B(0000000000000000);
    map[95] = B(0000011111110000);
    map[96] = B(0000000000000000);
    map[97] = B(0000111000000000);
    map[98] = B(0000000001110000);
    map[99] = B(1111000000000111);
    map[100] = B(0000000000000000);
    map[101] = B(0000001110110000);
    map[102] = B(1110000000000111);
    map[103] = B(0000011110000000);
    map[104] = B(0000000000111111);
    map[105] = B(0001110000000000);
    map[106] = B(0000000001100000);
    map[107] = B(0000011111110000);
    map[108] = B(0000000000000000);
    map[109] = B(0001100000011111);
    map[110] = B(0000000000000000);
    map[111] = B(1111111110000000);
    map[112] = B(0000000000001111);
    map[113] = B(0000000001110000);
    map[114] = B(1111110000000000);
    map[115] = B(0000000000000000);
    map[116] = B(1111000000000111);
    map[117] = B(1111111100111111);
    map[118] = B(0001111111111000);
}

void map_draw(GlobalState *const global_state, float background_position)
{
    // float background_position = global_state->paper->position.y;
    for (int i = background_position; i < background_position + 10; i++)
    {
        /*
            using a u_int32_t here so that bits
            that have been shifted out can still
            be read.
        */
        if (i > MAP_HEIGHT - 1 || i < 0)
        {
            continue;
        }
        uint32_t currentRow = global_state->map[i];
        for (unsigned int j = 0; j < MAP_WIDTH; j++)
        {
            /*
                0x8000 is 1 with 15 zeros
                00000000000000001000000000000000 - 0x8000
                00000000000000001111111001111111 - map data (currentRow)
                using & will result in:
                00000000000000001000000000000000
                the above number will evaluate to true

                OR

                00000000000000001000000000000000 - 0x8000
                00000000000000000111111001111111 - map data (currentRow)
                using & will result in:
                00000000000000000000000000000000
                the above number will result in false
            */
            if (currentRow & 0x8000)
            {
                Rectangle ground_to_draw = {8 * SPRITE_SIZE, 0.0f, SPRITE_SIZE, SPRITE_SIZE};
                Vector2 tile_position = {
                    j * SPRITE_SIZE,
                    i * SPRITE_SIZE - background_position * SPRITE_SIZE};

                // don't draw corner tiles on the edge of the screen
                if (j != 0 && j != MAP_WIDTH - 1)
                {
                    // if the bit to the left is 0, use the right facing ground sprite
                    if (!(currentRow & 0x4000))
                    {
                        ground_to_draw.x = 9 * SPRITE_SIZE;
                    }

                    // if the bit to the right is 0, use the left facing ground tile
                    if (!(currentRow & 0x10000))
                    {
                        ground_to_draw.x = 7 * SPRITE_SIZE;
                    }
                }

                DrawTextureRec(*global_state->sprite_sheet, ground_to_draw, tile_position, WHITE);
            }

            // bit shift currentRow to the left, so the bit to the right will be drawn
            currentRow <<= 1;
        }
    }
}