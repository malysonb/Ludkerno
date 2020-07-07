#pragma once
#include "../Game.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"
#include "../EntityMNGR.hpp"
#include "Sprite.hpp"

class Cactus : public Component
{
    private:

    public:
    void Init()
    {
        Active = true;
        int myFrame = Game::Rand(0,4);
        Base->SetSprite("Assets/cactus.png",16,32,4);
        Base->getComponent<Sprite>()->SetupAnimation(myFrame,0,10000);
        Base->getComponent<Sprite>()->SetAnimation(myFrame);
        Base->getComponent<Sprite>()->OriginPoint = {8, 32};
    }

    void Update()
    {
        Base->transform->velocity.X = -3;
    }
    void Render()
    {

    }
    const char* GetName() {return "Cactus";}
};