#include <iostream>
//#include "include/Interpreter.hpp"
#include "LudkernoLib.hpp"
#include "GameCode/PlatformScene.hpp"
#include "GameCode/Cena.hpp"
#include "GameCode/TileScene.hpp"
bool isWeb = false;
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
isWeb = true;
#endif

//void emscripten_set_main_loop(void *func, int fps, int simulate_infinite_loop);

Ludkerno *game = nullptr;

extern "C"
{
    int SDL_main(int argc, char **argv)
    {
        std::cout << "Loaded " << argc << "Arguments: ";
        for (int i = 0; i < argc; i++)
        {
            std::cout << i << " - " << argv[i] << std::endl;
        }
        //Uint32 lastframe = SDL_GetTicks();
        SceneMngr::GetInstance()->insertScene(new PlatformScene);
        Ludkerno::EngineInit("Ludkerno", 854, 480);
        if (isWeb)
        {
            
        }
        else
        {
            Ludkerno::Loop();
        }
        /*#ifdef __EMSCRIPTEN__ #else #endif emscripten_set_main_loop(game->Loop(), 0, 1);*/
        Ludkerno::Clear();
        return 0;
    }
}