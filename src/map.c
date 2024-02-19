#include "types.h"
#include "global_state.h"
#include "map.h"
#include "constants.h"

void map_init(uint16_t *map)
{
    /*
        this is all the map data same as
        the map from https://ticalc.org/archives/files/fileinfo/341/34139.html
        1: 8x8 tile exists on an 8x8 grid
        0: no 8x8 tile
    */

    map[0] = 0b1111111001111111;
    map[1] = 0b1111110000111111;
    map[2] = 0b1111000000001111;
    map[3] = 0b0000000000000000;
    map[4] = 0b0000000000000000;
    map[5] = 0b0000000000011111;
    map[6] = 0b0000000000000000;
    map[7] = 0b0000000000000000;
    map[8] = 0b1111111100000000;
    map[9] = 0b0000000000000000;
    map[10] = 0b0000000000000000;
    map[11] = 0b0000000000000000;
    map[12] = 0b1111000000111111;
    map[13] = 0b0000000000000000;
    map[14] = 0b0000000000000000;
    map[15] = 0b0000000011110000;
    map[16] = 0b0000000000000000;
    map[17] = 0b0000000000110000;
    map[18] = 0b0000000000000000;
    map[19] = 0b0000000000000000;
    map[20] = 0b1111111110000000;
    map[21] = 0b0000000000000111;
    map[22] = 0b1111000000000000;
    map[23] = 0b0000000000000000;
    map[24] = 0b0000000000000000;
    map[25] = 0b0000000000000000;
    map[26] = 0b0000000011110000;
    map[27] = 0b0000000000000000;
    map[28] = 0b0000000000110000;
    map[29] = 0b0000000000000000;
    map[30] = 0b1111110000000111;
    map[31] = 0b0000000000000000;
    map[32] = 0b0000000011111111;
    map[33] = 0b0000000000000000;
    map[34] = 0b0000000000000000;
    map[35] = 0b0000000111110000;
    map[36] = 0b0000000000000000;
    map[37] = 0b0000000000000000;
    map[38] = 0b0000000011000000;
    map[39] = 0b1110000000000111;
    map[40] = 0b1110000000000111;
    map[41] = 0b0000000000000000;
    map[42] = 0b1111111111000000;
    map[43] = 0b0000000000000000;
    map[44] = 0b1111100000000000;
    map[45] = 0b0000000000111111;
    map[46] = 0b0000000000000000;
    map[47] = 0b0000001111110000;
    map[48] = 0b0000000000000000;
    map[49] = 0b0000000000000000;
    map[50] = 0b0000000000000000;
    map[51] = 0b0000000000000000;
    map[52] = 0b0001111100001111;
    map[53] = 0b0000000000000000;
    map[54] = 0b0000000000000000;
    map[55] = 0b0000001111110000;
    map[56] = 0b0000000000000000;
    map[57] = 0b0000000000000000;
    map[58] = 0b1111110000000000;
    map[59] = 0b0000000000001111;
    map[60] = 0b0000000000000000;
    map[61] = 0b0000011110000000;
    map[62] = 0b0000000000000000;
    map[63] = 0b0000000001110000;
    map[64] = 0b0000000000000000;
    map[65] = 0b0000111111000000;
    map[66] = 0b0000000000000000;
    map[67] = 0b0000000001111111;
    map[68] = 0b0000000000000000;
    map[69] = 0b0000011000000000;
    map[70] = 0b0000000000000000;
    map[71] = 0b0000001111000000;
    map[72] = 0b0000000000000000;
    map[73] = 0b0000000000110000;
    map[74] = 0b0000111100000000;
    map[75] = 0b0000000000000000;
    map[76] = 0b0001100000111111;
    map[77] = 0b0000000000000000;
    map[78] = 0b0000000000000000;
    map[79] = 0b1111111111000000;
    map[80] = 0b0000000000000000;
    map[81] = 0b0000000011110000;
    map[82] = 0b0000000000000000;
    map[83] = 0b0001111001100000;
    map[84] = 0b0000000000000000;
    map[85] = 0b0000000000000000;
    map[86] = 0b0000110011000111;
    map[87] = 0b0000000000011111;
    map[88] = 0b0000000000000000;
    map[89] = 0b1111000000001111;
    map[90] = 0b0000000001100000;
    map[91] = 0b1111000000000000;
    map[92] = 0b0000000110000000;
    map[93] = 0b0000110000110000;
    map[94] = 0b0000000000000000;
    map[95] = 0b0000011111110000;
    map[96] = 0b0000000000000000;
    map[97] = 0b0000111000000000;
    map[98] = 0b0000000001110000;
    map[99] = 0b1111000000000111;
    map[100] = 0b0000000000000000;
    map[101] = 0b0000001110110000;
    map[102] = 0b1110000000000111;
    map[103] = 0b0000011110000000;
    map[104] = 0b0000000000111111;
    map[105] = 0b0001110000000000;
    map[106] = 0b0000000001100000;
    map[107] = 0b0000011111110000;
    map[108] = 0b0000000000000000;
    map[109] = 0b0001100000011111;
    map[110] = 0b0000000000000000;
    map[111] = 0b1111111110000000;
    map[112] = 0b0000000000001111;
    map[113] = 0b0000000001110000;
    map[114] = 0b1111110000000000;
    map[115] = 0b0000000000000000;
    map[116] = 0b1111000000000111;
    map[117] = 0b1111111100111111;
    map[118] = 0b0001111111111000;
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
        if (i > MAP_HEIGHT - 1)
        {
            return;
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