#include <iostream>
#include "Ludkerno.hpp"
#include "GameCode/Cena.hpp"

Game *game = nullptr;

int main()
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    game = new Game();

    game->EngineInit("Ludkerno", 800, 600);
    game->LoadScene(new cena);

    while(game->IsRunning())
    {
        frameStart = SDL_GetTicks();
        game->HandleEvents();
        game->Update();
        game->Render();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->Clear();
    return 0;
}