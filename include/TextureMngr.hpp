#pragma once
#include "Game.hpp"

#ifdef SDL_Image_Path
#include SDL_Image_Path
#else
#include "../ThirdParty/x86/include/SDL2/SDL_image.h"
#endif

class TextureMngr{
    public:
    static SDL_Texture* LoadTexture(const char* filename);
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    static SDL_Texture* LoadTexture_RW(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};