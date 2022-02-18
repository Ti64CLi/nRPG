#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <libndls.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT)

typedef struct
{
    uint16_t width, height;
    uint16_t *data;
} sprite_t;

typedef struct
{
    uint16_t width, height;
    uint16_t *buffer;
} buffer_t;

typedef struct
{
    uint16_t width, height;
    sprite_t *tiles;
    uint16_t tile_width, tile_height;
    uint16_t *tilemap;
} tilemap_t;

void gFillScreen(buffer_t *screen_buffer, uint16_t color);
void gDrawSprite(buffer_t *screen_buffer, uint16_t x, uint16_t y, sprite_t sprite, uint8_t zoom);
void gDrawTileMap(buffer_t *screen_buffer, tilemap_t tilemap, uint16_t x, uint16_t y, uint16_t tilemap_x, uint16_t tilemap_y, uint16_t tilemap_w, uint16_t tilemap_h, uint8_t zoom, int8_t xoffset, int8_t yoffset);

#endif