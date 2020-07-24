#pragma once
#include "../Ludkerno.hpp"
#include "Generator.hpp"
#include "Input.hpp"

class cena : public Scene
{
private:
public:
    void Setup()
    {
        Entity *Player = Game::EntityManager.Add();
        Player->SetSprite("./Assets/Dino.png", 16, 16, 1);
        Player->GetSprite()->SetupAnimation(0, 1, 200);
        Player->GetSprite()->OriginPoint = {8, 16};
        Player->transform->SetScreenPosition(Game::screen.DynamicHPosition(15), Game::screen.DynamicVPosition(50));
        Player->AddComponent<PlatformPhysics>(Player);
        Player->getComponent<PlatformPhysics>()->Init();
        Player->AddComponent<Input>(Player);
        Player->getComponent<Input>()->Init();
        Player->AddComponent<Collider>(Player);
        Player->getComponent<Collider>()->Init();
        Entity *CactusGenerator = Game::EntityManager.Add();
        CactusGenerator->AddComponent<Generator>();
        CactusGenerator->getComponent<Generator>()->Init();
    }
};