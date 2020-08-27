#include "../ThirdParty/x86/include/minizip/unzip.h"
#include "../include/PkgMngr.hpp"

void PkgMngr::Init()
{
    /*size = 0;
    Assets_images = unzOpen("Assets/Sprites.rpk");
    if (Assets_images == nullptr)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Missing File!", "'Sprites.rpk' not found!\nSome weird stuff may happen", NULL);
    }*/
}

/*Uint8 *PkgMngr::ReadOneFile(const char *filename)
{
    Uint8 *Buffer;
    int iterator;
    iterator = unzLocateFile(Assets_images, filename, 0);
    if (iterator != UNZ_OK)
    {
        printf("%d", iterator);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Cant read this file!", "Can't locate this file!", NULL);
    }
    iterator = unzGetCurrentFileInfo(Assets_images, &info, NULL, 0, NULL, 0, NULL, 0);
    if (iterator != UNZ_OK)
    {
        printf("%d", iterator);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Cant read this file!", "Can't get current file info!", NULL);
    }
    iterator = unzOpenCurrentFile(Assets_images);
    if (iterator != UNZ_OK)
    {
        printf("%d", iterator);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Cant read this file!", "Can't open current file!", NULL);
    }
    size = info.uncompressed_size;
    Buffer = new Uint8[size];
    iterator = unzReadCurrentFile(Assets_images, Buffer, size);
    return Buffer;
}*/

char *PkgMngr::ReadOneFile(const char* filename)
{
    return 0;
}