#pragma once
#include "../Ludkerno.hpp"
#include "PlatformerInput.hpp"

class PlatformScene : public Scene
{
    public:
    Entity* Player;
    void Setup()
    {
        Player = Game::EntityManager.Add();
        Player->SetSprite("./Assets/aliisheet.png",16,16,4);
        Player->GetSprite()->SetOrigin(8,16);
        Player->GetSprite()->SetupAnimation(0,1,1000);
        Player->GetSprite()->SetupAnimation(1,5,50);
        Player->AddComponent<PlatformerInput>(Player);
        Player->getComponent<PlatformerInput>()->Init();
        Player->transform->SetScreenPosition(Game::screen.DynamicHPosition(50), Game::screen.DynamicVPosition(50));
    }
    void Update()
    {
        SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    }
};