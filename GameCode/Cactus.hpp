#pragma once
#include "../Ludkerno.hpp"

class Cactus : public Component
{
    private:
    public:
    int speed = -300;
    void Init()
    {
        Active = true;
        int myFrame = Game::Rand(0,4);
        Base->SetSprite("./Assets/cactus.png",16,32,4);
        Base->getComponent<Sprite>()->SetupAnimation(myFrame,0,500);
        Base->getComponent<Sprite>()->SetAnimation(myFrame);
        Base->getComponent<Sprite>()->OriginPoint = {8, 32};
    }

    void Update()
    {
        float S = speed * Game::DeltaTime;
        //S = S / Game::FrameRate;
        Base->transform->velocity.X = S;
    }
    void Render()
    {
        
    }
    void Disable()
    {
        Base->transform->velocity.X = 0;
    }
    const char* GetName() {return "Cactus";}
};