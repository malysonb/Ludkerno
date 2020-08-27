#include <iostream>
#include "Ludkerno.hpp"
#include "GameCode/PlatformScene.hpp"

Game *game = nullptr;

int main()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime = SDL_GetTicks();
    game = new Game();
    Game::sceneMngr.insertScene(new PlatformScene);
    game->EngineInit("Ludkerno", 1360, 768);
    while (game->IsRunning())
    {
        frameStart = SDL_GetTicks();
        game->HandleEvents();
        game->Update();
        game->Render();
        frameTime = SDL_GetTicks() - frameStart;
        Game::FrameRate = frameTime != 0 ? 1000 / (frameDelay + frameTime) : Game::FrameRate;
        Game::FrameRate == 0 ? Game::FrameRate++ : Game::FrameRate;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->Clear();
    return 0;
}