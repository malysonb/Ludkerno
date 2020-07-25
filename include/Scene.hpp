#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * Simple scene template to you make your own scenes.
 */
#include "Game.hpp"
class Scene
{
    public:
    Scene();
    ~Scene();

    void LoadMap(int sX, int sY, int **MapCode);
    void DrawMap(int layer = 0);
    virtual void Setup() = 0;
    void Init();
    virtual void Update() = 0;

    private:
    SDL_Rect srcRect, destRect;
    SDL_Texture* TileMap;
    int canDraw = false;
    int **map;

};