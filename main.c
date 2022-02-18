#include <stdio.h>
#include <stdlib.h>
#include <libndls.h>

#include "utils.h"
#include "graphics.h"
#include "gfx/tileset_yellowtown.h"
#include "tilemap_yellowtown.h"

int main()
{
    buffer_t screen_buffer = {
        .width = SCREEN_WIDTH,
        .height = SCREEN_HEIGHT,
        .buffer = NULL};

    if (!(screen_buffer.buffer = malloc(SCREEN_SIZE * sizeof(uint16_t))))
        return EXIT_FAILURE;

    tilemap_t tilemap = {
        .width = TILEMAP_WIDTH,
        .height = TILEMAP_HEIGHT,
        .tiles = NULL,
        .tile_width = 16,
        .tile_height = 16,
        .tilemap = NULL};

    if (!(tilemap.tiles = malloc(TILES_NUMBER * sizeof(sprite_t))))
        return EXIT_FAILURE;

    for (int i = 0; i < TILES_NUMBER; i++)
    {
        tilemap.tiles[i] = (sprite_t){
            .width = tilemap.tile_width,
            .height = tilemap.tile_height,
            .data = (uint16_t *)(tileset_yellowtown + i * (tilemap.tile_width * tilemap.tile_height))};
    }

    tilemap.tilemap = tilemap_yellowtown;

    lcd_init(SCR_320x240_565); // 320x240 16bits buffer

    char refresh = 1;
    uint16_t posx = 0, posy = 0;
    int16_t xoffset = 0, yoffset = 0;
    uint16_t background_color = 0;

    uint16_t tiles_per_line = SCREEN_WIDTH / tilemap.tile_width;
    uint16_t tiles_per_column = SCREEN_HEIGHT / tilemap.tile_height;

    while (!isKeyPressed(KEY_NSPIRE_ESC))
    {
        if (refresh)
        {
            gFillScreen(&screen_buffer, background_color);
            gDrawTileMap(&screen_buffer, tilemap, 0, 0, posx, posy, tiles_per_line, tiles_per_column, 1, xoffset, yoffset);
            lcd_blit(screen_buffer.buffer, SCR_320x240_565);

            refresh = 0;
        }

        if (isKeyPressed(KEY_NSPIRE_LEFT) && posx > 0)
        {
            posx--;
            // xoffset = -tilemap.tile_width;

            refresh = 1;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHT) && posx < tilemap.width - tiles_per_line)
        {
            posx++;
            // xoffset = tilemap.tile_width;

            refresh = 1;
        }
        if (isKeyPressed(KEY_NSPIRE_UP) && posy > 0)
        {
            posy--;
            // yoffset = -tilemap.tile_height;

            refresh = 1;
        }
        if (isKeyPressed(KEY_NSPIRE_DOWN) && posy < tilemap.height - tiles_per_column)
        {
            posy++;
            // yoffset = tilemap.tile_height;

            refresh = 1;
        }
    }

    lcd_init(SCR_TYPE_INVALID);

    free(screen_buffer.buffer);
    free(tilemap.tiles);
    // free(tilemap.tilemap);

    return EXIT_SUCCESS;
}