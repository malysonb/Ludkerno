#include "../include/Game.hpp"
#include "../include/Camera.hpp"
#include "../include/Scene.hpp"
#include "../include/TextureMngr.hpp"
#include "../include/Tilemap.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
    //TileMap = TextureMngr::LoadTexture("Assets/dirt.png");
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = 0;
    destRect.y = 0;
    srcRect.h = 32;
    srcRect.w = 32;
    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
}

void Scene::LoadMap(int sX, int sY, int *MapCode)
{
    M_SceneCols = sX;
    M_SceneRows = sY;
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

void Scene::DrawMap()
{
    if (canDraw)
    {
        int type = 0;
        for (int row = 0; row < M_SceneRows; row++)
        {
            for (int col = 0; col < M_SceneCols; col++)
            {
                int coliterator = 0;
                int rowiterator = 0;
                type = map[row][col];
                int temp = type;
                while (temp >= M_tile->SheetH)
                {
                    coliterator += M_tile->SheetH;
                    rowiterator++;
                    temp -= M_tile->SheetH;
                }
                srcRect.x = M_tile->TileX * type - (coliterator * M_tile->TileX);
                srcRect.y = M_tile->TileY * rowiterator;
                destRect.x = col * destRect.w - static_cast<int>(Game::camera->relativePosition.X);
                destRect.y = row * destRect.h - static_cast<int>(Game::camera->relativePosition.Y);
                TextureMngr::Draw(Scene_TileMap, srcRect, destRect);
            }
        }
    }
}

void Scene::Scene_SetTilemap(const char *filepath)
{
    Tilemap *tiles = new Tilemap(filepath, 3, 3);
    M_tile = tiles;
    Scene_TileMap = tiles->GetTileTexture();
    srcRect.h = tiles->TileY;
    srcRect.w = tiles->TileX;
    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
}

void Scene::Scene_SetTilemap(const char *filename, int sheets_H, int sheets_V, int tile_X, int tile_Y)
{
    Tilemap *tiles = new Tilemap(filename, sheets_H, sheets_V, tile_X, tile_Y);
    M_tile = tiles;
    Scene_TileMap = tiles->GetTileTexture();
    srcRect.h = tiles->TileY;
    srcRect.w = tiles->TileX;
    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
}

Vector2 Scene::GetTileDim()
{
    return Vector2(static_cast<float>(M_tile->TileX), static_cast<float>(M_tile->TileX));
}
