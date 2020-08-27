#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * @date 24/07/2020
 * "You can compress your files here before to use in your released version!"
 */
#include "Game.hpp"
#include "../ThirdParty/x86/include/minizip/unzip.h"

typedef void* unzFile;

class PkgMngr
{
private:
public:
    int size;
    unzFile Assets_images;
    unz_file_info info;
    void Init();
    char *ReadOneFile(const char *filename);
};