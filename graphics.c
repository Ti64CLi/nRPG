#include <stdlib.h>
#include <stdio.h>

#include "graphics.h"

void gFillScreen(buffer_t *screen_buffer, uint16_t color)
{
    for (uint16_t i = 0; i < screen_buffer->height; i++)
    {
        for (uint16_t j = 0; j < screen_buffer->width; j++)
        {
            screen_buffer->buffer[i * screen_buffer->width + j] = color;
        }
    }
}

void gDrawSprite(buffer_t *screen_buffer, uint16_t x, uint16_t y, sprite_t sprite, uint8_t zoom)
{
    for (uint16_t i = 0; i < sprite.height; i++)
    {
        for (uint16_t j = 0; j < sprite.width; j++)
        {
            for (uint8_t iz = 0; iz < zoom; iz++)
            {
                for (uint8_t jz = 0; jz < zoom; jz++)
                {
                    uint16_t ycoord = i * zoom + y + iz, xcoord = j * zoom + x + jz;
                    if (xcoord < screen_buffer->width && ycoord < screen_buffer->height)
                        screen_buffer->buffer[ycoord * screen_buffer->width + xcoord] = sprite.data[i * sprite.width + j];
                }
            }
        }
    }
}

void gDrawTileMap(buffer_t *screen_buffer, tilemap_t tilemap, uint16_t x, uint16_t y, uint16_t tilemap_x, uint16_t tilemap_y, uint16_t tilemap_w, uint16_t tilemap_h, uint8_t zoom, int8_t xoffset, int8_t yoffset)
{
    for (uint16_t i = 0; i < tilemap_h; i++)
    {
        for (uint16_t j = 0; j < tilemap_w; j++)
        {
            gDrawSprite(screen_buffer, x + j * tilemap.tile_width * zoom + xoffset, y + i * tilemap.tile_height * zoom + yoffset, tilemap.tiles[tilemap.tilemap[(i + tilemap_y) * tilemap.width + j + tilemap_x]], zoom);
        }
    }
}