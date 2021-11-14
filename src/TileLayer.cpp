#include "../include/Game.hpp"
#include "../include/TileLayer.hpp"
#include "../include/Tilemap.hpp"
#include "../include/Camera.hpp"
#include "../include/TextureMngr.hpp"

void TileLayer::SetTilemap(const char *filename, int sheets_H, int sheets_V, int tile_X, int tile_Y)
{
    Tilemap *tiles = new Tilemap(filename, sheets_H, sheets_V, tile_X, tile_Y);
    m_tile = tiles;
    m_TileMap = tiles->GetTileTexture();
    src.h = tiles->TileY;
    src.w = tiles->TileX;
    dest.h = src.h;
    dest.w = src.w;
}

void TileLayer::LoadMap(int sX, int sY, int *MapCode)
{
    cols = sX;
    rows = sY;
    map = new int *[sY];
    int iterator = 0;
    for (int row = 0; row < sY; row++)
    {
        map[row] = new int[sX];
        for (int col = 0; col < sX; col++)
        {
            map[row][col] = MapCode[iterator];
            iterator++;
        }
    }
    canDraw = true;
}

void TileLayer::Render()
{
    if (canDraw)
    {
        int id = 0;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                //int coliterator = 0;
                //int rowiterator = 0;
                id = map[row][col];
                int x = (id % m_tile->SheetH);
                int y = (id / m_tile->SheetH);
                src.x = m_tile->TileX * x;
                src.y = m_tile->TileY * y;
                dest.x = col * dest.w - static_cast<int>(Game::camera->relativePosition.X);
                dest.y = row * dest.h - static_cast<int>(Game::camera->relativePosition.Y);
                TextureMngr::Draw(m_tile->GetTileTexture(), src, dest);
            }
        }
    }
}

void TileLayer::setParallax(float value)
{
    this->m_parallax = value;
}

float TileLayer::getParallax()
{
    return m_parallax;
}

TileLayer::~TileLayer()
{
    
}