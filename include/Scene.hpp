#pragma once
#include "Game.hpp"
class Scene
{
    public:
    Scene();
    ~Scene();

    void LoadMap(int mapcode[20][25]);
    void DrawMap();

    private:
    SDL_Rect srcRect, destRect;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];

};