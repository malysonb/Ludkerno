#include "../include/Tilemap.hpp"
#include "../include/TextureMngr.hpp"

#ifdef Release
    bool release_v = true;
#else
    bool release_v = false;
#endif

void Tilemap::SetTileMapFile(const char *filename)
{
    MapTexture = release_v ? TextureMngr::LoadTexture_RW(filename) : TextureMngr::LoadTexture(filename);
}