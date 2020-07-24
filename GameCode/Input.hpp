#pragma once
#include "../Ludkerno.hpp"

class Input : public Component
{
public:
    Transform *transform;
    PlatformPhysics* PF;
    void Init()
    {
        Active = true;
        transform = Base->transform;
        Debug::log("Initializing Input", Debug::INFO);
        PF = Base->getComponent<PlatformPhysics>();
    }

    const char *GetName() { return "Input"; }
    bool able = true;
    bool onTop = false;
    int v = 0;
    void Update()
    {
        if(transform->GetScreenPosition().Y >= Game::screen.DynamicVPosition(50))
        {
            able = true;
            onTop = false;
            PF->isOnGround = true;
            transform->SetScreenPosition(transform->GetScreenPosition().X ,Game::screen.DynamicVPosition(50));
        }
        else{
            PF->isOnGround = false;
        }
        if(Game::key.keycode.UP)
        {
            PF->ApplyForce(-10,Vector2::AY); 
        }
        else
        {
            PF->ApplyForce(0,Vector2::AY); 
        }
        if(Base->getComponent<Collider>()->isColliding)
        {
            v++;
            std::cout << "colidiu: " << v << std::endl;
        }
        /*transform->velocity.Y = Game::key.keycode.Y_Axis * 2;
        transform->velocity.X = Game::key.keycode.X_Axis * 2;
        if(transform->position.X >= Game::camera->middle.X)
        {
            Game::camera->Move(Vector2::AX, transform->velocity.X);
        }
        if(transform->position.Y >= Game::camera->middle.Y)
        {
            Game::camera->Move(Vector2::AY, transform->velocity.Y);
        }*/
    }

    void Render()
    {
        /*Not Implemented*/
    }
};