#pragma once
#include <string>
#include "../LudkernoLib.hpp"
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
        Player = EntityMngr::GetInstance()->Add();
        Player->SetSprite("./Assets/dino.png", 16, 16, 1);
        Player->GetSprite()->SetupAnimation(0, 1, 100);
        Player->GetSprite()->OriginPoint = {8, 16};
        Player->transform->SetScreenPosition(Ludkerno::screen.DynamicHPosition(15), Ludkerno::screen.DynamicVPosition(50));
        Player->AddComponent<PlatformPhysics>(Player);
        Player->getComponent<PlatformPhysics>()->Init();
        Player->AddComponent<Input>(Player);
        Player->getComponent<Input>()->Init();
        Player->AddComponent<Collider>(Player);
        Player->getComponent<Collider>()->Init();
        CactusGenerator = EntityMngr::GetInstance()->Add();
        CactusGenerator->AddComponent<Generator>();
        CactusGenerator->getComponent<Generator>()->Init();
    }

    void Update()
    {
        if(Player->getComponent<Input>()->died)
        {
            Player->getComponent<Input>()->Disable();
            CactusGenerator->getComponent<Generator>()->Disable();
            //Obj* temp = EntityMngr::GetInstance()->.SceneEntities.front();
            for(int i = 0; i <static_cast<int>(EntityMngr::GetInstance()->SceneEntities.size()) ; i++)
            {
                Entity* iterator = EntityMngr::GetInstance()->SceneEntities[i]->GetEntity();
                if(iterator->getComponent<Cactus>() != nullptr)
                {
                    iterator->getComponent<Cactus>()->Disable();
                }
                if(iterator->getComponent<Collider>() != nullptr)
                {
                    iterator->getComponent<Collider>()->Disable();
                }
            }
            if(Ludkerno::key.keycode.QUIT || Ludkerno::key.keycode.START || Ludkerno::key.keycode.LEFT_CLICK)
            {
                SceneMngr::GetInstance()->setScene(0);
                return;
            }
        }
        SDL_SetRenderDrawColor(Ludkerno::renderer,255,255,255,255);
    }
};