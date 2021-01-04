#include "../include/Tilemap.hpp"
#include "../include/TextureMngr.hpp"

#ifdef Release
    bool release_v = true;
#else
    bool release_v = false;
#endif

Tilemap::Tilemap(const char *filename, int sheets_H, int sheets_V, int tile_X, int tile_Y)
{
    SetTileMapFile(filename);
    SheetH = sheets_H;
    SheetV = sheets_V;
    TileX = tile_X;
    TileY = tile_Y;
}

Tilemap::Tilemap(const char *filename)
{
    SheetH = 3;
    SheetV = 3;
    TileX = 32;
    TileY = 32;
}

void Tilemap::SetTileMapFile(const char *filename)
{
    TileTexture = release_v ? TextureMngr::LoadTexture_RW(filename) : TextureMngr::LoadTexture(filename);
}