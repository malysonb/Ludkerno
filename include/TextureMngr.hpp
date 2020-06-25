#pragma once
#include "Game.hpp"
#include "../ThirdParty/x64/include/SDL2/SDL_image.h"

class TextureMngr{
    public:
    static SDL_Texture* LoadTexture(const char* filename);
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};