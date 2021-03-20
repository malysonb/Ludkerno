#include "../include/TextureMngr.hpp"
#include "../include/Debug.hpp"

#include "RadiPako.hpp"

/*#ifdef MSVCcompiler
#include "../include/RadiPako.h"
#elif GCCcompiler
extern "C"
{
    #include "../include/RadiPako.h"
}
#else
#include "../include/RadiPako.h"
#endif*/

SDL_Texture* TextureMngr::LoadTexture(const char* filename)
{
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return Tex;
}

SDL_Texture* TextureMngr::LoadTexture(const char* filename, SDL_Renderer* ren)
{
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* Tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    return Tex;
}


SDL_Texture* TextureMngr::LoadTexture_RW(const char* filename)
{
    SDL_RWops* src;
    RadiPako::RPK *rpk_f = RadiPako::LoadRPKFile("./Assets/Sprites.rpk");
    RadiPako::RPK_File *file = RadiPako::GetFile(rpk_f, filename);
    if(rpk_f == nullptr)
    {
        Debug::log("This file cant be found!", Debug::Level::ERROR);
    }
    unsigned char* buff = RadiPako::GetFile_Content_Uchar(file);
    //unsigned char* buff = RPK_GetFile_Uchar("./Assets/Sprites.rpk",filename);
    if(buff == NULL)
    {
        Debug::log("This file doesn't exists!", Debug::Level::ERROR);
    }
    src = SDL_RWFromMem(buff, unsigned (file->getSize()));
    SDL_Surface* surface = IMG_Load_RW(src,1);
    SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    delete rpk_f;
    delete buff;
    return Tex;
}

void TextureMngr::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}