#include "../include/Game.hpp"
#include "../include/Camera.hpp"
#include "../include/Scene.hpp"
#include "../include/TextureMngr.hpp"

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

void Scene::LoadMap(int sX, int sY, int **MapCode)
{
    map = new int *[sY];
    for (int row = 0; row < sY; row++)
    {
        map[row] = new int[sX];
        for (int col = 0; col < sX; col++)
        {
            map[row][col] = MapCode[row][col];
        }
    }
    canDraw = true;
}

void Scene::DrawMap()
{
    if (canDraw)
    {
        int type = 0;
        for (int row = 0; row < 20; row++)
        {
            for (int col = 0; col < 25; col++)
            {
                type = map[row][col];
                srcRect.x = 32 * type;
                destRect.x = col * destRect.w - static_cast<int>(Game::camera->relativePosition.X);
                destRect.y = row * destRect.h - static_cast<int>(Game::camera->relativePosition.Y);
                switch (type)
                {
                case 0:
                    TextureMngr::Draw(TileMap, srcRect, destRect);
                    break;
                case 1:
                    TextureMngr::Draw(TileMap, srcRect, destRect);
                    break;
                case 2:
                    TextureMngr::Draw(TileMap, srcRect, destRect);
                    break;
                default:
                    break;
                }
            }
        }
    }
}