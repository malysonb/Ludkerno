#pragma once
#include "Game.hpp"
#include "Object.hpp"

class Tilemap : public Object
{
    SDL_Texture *TileTexture;
public:
    /**
     * Starts Tilemap.
     * @param filename receives the spritesheet path.
     **/
    Tilemap(const char *filename);

    /**
     * Starts Tilemap.
     **/
    Tilemap();

    /**
     * Starts Tilemap.
     * @param filename receives the spritesheet path.
     * @param sheets_H set how many tiles it have in the horizontal axis.
     * @param sheets_V set how many tiles it have in the vertical axis.
     * @param tile_X set the tile size in the X axis. Default is 32px.
     * @param tile_Y set the tile size in the Y axis. Default is 32px.
     **/
    Tilemap(const char *filename, int sheets_H, int sheets_V, int tile_X = 32, int tile_Y = 32);

    int TileX, TileY;
    int SheetH, SheetV;

    /**
     * Set the tilemap file and loads it in the memory.
     * @param filename Path to the file.
     **/
    void SetTileMapFile(const char *filename);

    SDL_Texture *GetTileTexture()
    {
        return TileTexture;
    }
};