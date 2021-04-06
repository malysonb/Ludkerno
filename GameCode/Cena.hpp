#pragma once
#include <string>
#include "../Ludkerno.hpp"
#include "Generator.hpp"
#include "Input.hpp"

class cena : public Scene
{
private:
public:
    bool finalized = false;
    Entity *Player;
    Entity *CactusGenerator;
    void Setup()
    {
        Player = Game::EntityManager.Add();
        Player->SetSprite("./Assets/dino.png", 16, 16, 1);
        Player->GetSprite()->SetupAnimation(0, 1, 100);
        Player->GetSprite()->OriginPoint = {8, 16};
        Player->transform->SetScreenPosition(Game::screen.DynamicHPosition(15), Game::screen.DynamicVPosition(50));
        Player->AddComponent<PlatformPhysics>(Player);
        Player->getComponent<PlatformPhysics>()->Init();
        Player->AddComponent<Input>(Player);
        Player->getComponent<Input>()->Init();
        Player->AddComponent<Collider>(Player);
        Player->getComponent<Collider>()->Init();
        CactusGenerator = Game::EntityManager.Add();
        CactusGenerator->AddComponent<Generator>();
        CactusGenerator->getComponent<Generator>()->Init();
    }

    void Update()
    {
        if(Player->getComponent<Input>()->died)
        {
            CactusGenerator->getComponent<Generator>()->Disable();
            //Obj* temp = Game::EntityManager.SceneEntities.front();
            for(int i = 0; i <static_cast<int>(Game::EntityManager.SceneEntities.size()) ; i++)
            {
                Entity* iterator = Game::EntityManager.SceneEntities[i]->GetEntity();
                if(iterator->getComponent<Cactus>() != nullptr)
                {
                    iterator->getComponent<Cactus>()->Disable();
                }
                if(iterator->getComponent<Collider>() != nullptr)
                {
                    iterator->getComponent<Collider>()->Disable();
                }
            }
            if(Game::key.keycode.QUIT || Game::key.keycode.START)
            {
                Game::sceneMngr.setScene(0);
            }
        }
        SDL_SetRenderDrawColor(Game::renderer,255,255,255,255);
    }
};