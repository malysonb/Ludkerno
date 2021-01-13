#pragma once
#include "../Ludkerno.hpp"
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
#include <string.h>

class Interpreter 
{
private:
public:
    static void ReadRPC(const char *path)
    {

    }
    static void ReadRPC()
    {
        int offset = 0;
        RadiPako::RPK *rpk_f = RadiPako::LoadRPKFile("./Assets/Sprites.rpk");
        char* buffer = RadiPako::GetFile_Content(rpk_f, "./Assets/code.rpc");
        if(buffer == nullptr)
        {
            Debug::log("Bytecode not found!", Debug::Level::ERROR);
        }
        std::cout << buffer << std::endl;
    }
};