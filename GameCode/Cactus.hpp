#pragma once
#include "../Ludkerno.hpp"

class Cactus : public Component
{
    private:
    public:
    int speed = -5;
    void Init()
    {
        Active = true;
        int myFrame = Game::Rand(0,4);
        Base->SetSprite("Assets/cactus.png",16,32,4);
        Base->getComponent<Sprite>()->SetupAnimation(myFrame,0,500);
        Base->getComponent<Sprite>()->SetAnimation(myFrame);
        Base->getComponent<Sprite>()->OriginPoint = {8, 32};
    }

    void Update()
    {
        Base->transform->velocity.X = speed;
    }
    void Render()
    {

    }
    const char* GetName() {return "Cactus";}
};