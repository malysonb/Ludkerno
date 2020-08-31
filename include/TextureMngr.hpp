#pragma once
#include "Game.hpp"

#ifdef SDL_Image_Path
#include SDL_Image_Path
#else
#include <SDL2/SDL_image.h>
#endif

class TextureMngr{
    public:
    /**
     * Load the texture by the path.
     **/
    static SDL_Texture* LoadTexture(const char* filename);
    /**
     * @deprecated You dont need to refeer the Render anymore.
     **/ 
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    /**
     * Load a texture in an unsigned char buffer.
     * @param filename The filename of the texture.
     * @returns SDL_Texture
     **/
    static SDL_Texture* LoadTexture_RW(const char* filename);
    /**
     * Draw a texture on the screen.
     * @param tex The texture you want to draw.
     * @param src the rect from your source.
     * @param dest the rect where you want to draw on the screen.
     **/
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

/**
 * Contributors:
 * - @malysonb
 */