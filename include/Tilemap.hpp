#pragma once
#include "Game.hpp"
class Tilemap
{
    public:
    int tileSize;
    int SizeX, SizeY;
    SDL_Texture* MapTexture;
    void SetTileMapFile(const char *filename);
};