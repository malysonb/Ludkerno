#include "../include/TextureMngr.hpp"
#include "../ThirdParty/x86/include/zlib.h"
#include "../ThirdParty/x86/include/minizip/unzip.h"
#include "../include/PkgMngr.hpp"

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
    Uint8* buff = Game::pkgMngr.ReadOneFile(filename);
    int size = Game::pkgMngr.info.uncompressed_size;
    src = SDL_RWFromMem(buff, size);
    SDL_Surface* surface = IMG_Load_RW(src,1);
    SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return Tex;
}

void TextureMngr::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}