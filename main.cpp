#include <iostream>
//#include "include/Interpreter.hpp"
#include "Ludkerno.hpp"
#include "GameCode/PlatformScene.hpp"
#include "GameCode/Cena.hpp"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

Game *game = nullptr;

const int FPS = 60;
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime = SDL_GetTicks();

void gameloop()
{
    frameStart = SDL_GetTicks();
    game->HandleEvents();
    game->Update();
    game->Render();
    frameTime = SDL_GetTicks() - frameStart;
    Game::FrameRate = frameTime != 0 ? 1000 / (frameDelay + frameTime) : Game::FrameRate;
    Game::FrameRate == 0 ? Game::FrameRate++ : Game::FrameRate;
}

int main()
{
    frameTime = SDL_GetTicks();
    //Uint32 lastframe = SDL_GetTicks();
    game = new Game();
    Game::sceneMngr.insertScene(new PlatformScene);
    //Interpreter::ReadRPC();
    game->EngineInit("Ludkerno", 854, 480);
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(gameloop, 0, 1);
    #else
        while (game->IsRunning())
        {
            frameStart = SDL_GetTicks();
            game->HandleEvents();
            game->Update();
            game->Render();
            frameTime = SDL_GetTicks() - frameStart;
            Game::FrameRate = frameTime != 0 ? 1000 / (frameDelay + frameTime) : Game::FrameRate;
            Game::FrameRate == 0 ? Game::FrameRate++ : Game::FrameRate;
        }
        game->Clear();
    #endif
    return 0;
}