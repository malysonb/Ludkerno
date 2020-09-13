#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * Simple scene template to you make your own scenes.
 */
#include "Game.hpp"
#include "Tilemap.hpp"
class Scene
{
    public:
    Scene();
    ~Scene();

    void LoadMap(int sX, int sY, int *MapCode);
    void DrawMap();
    virtual void Setup() = 0;
    void Init();
    virtual void Update() = 0;
    void Scene_SetTilemap(const char *filepath);
    void Scene_SetTilemap(const char *filename, int sheets_H, int sheets_V, int tile_X = 32, int tile_Y = 32);
    int **map;
    int M_SceneCols, M_SceneRows;
    private:
    SDL_Texture* Scene_TileMap;
    Tilemap* M_tile;
    SDL_Rect srcRect, destRect;
    int canDraw = false;

};