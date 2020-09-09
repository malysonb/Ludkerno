#pragma once
#include "../Ludkerno.hpp"
#include "Cena.hpp"
#include "Cactus.hpp"
#include "Generator.hpp"

class Input : public Component
{
public:
    Transform *transform;
    PlatformPhysics *PF;
    void Init()
    {
        Active = true;
        transform = Base->transform;
        Debug::log("Initializing Input", Debug::INFO);
        PF = Base->getComponent<PlatformPhysics>();
        PF->mass = 100;
        PF->gravity = 10;
    }
    bool died = false;
    const char *GetName() { return "Input"; }
    bool able = true;
    bool onTop = false;
    int v = 0;
    void Update()
    {
        if (died)
        {
            if (Game::key.keycode.START)
            {
                Game::sceneMngr.setScene(0);
            }
        }
        if (transform->GetScreenPosition().Y >= Game::screen.DynamicVPosition(50))
        {
            able = true;
            onTop = false;
            PF->isOnGround = true;
            transform->SetScreenPosition(static_cast<int>(transform->GetScreenPosition().X), Game::screen.DynamicVPosition(50));
        }
        else
        {
            PF->isOnGround = false;
        }
        if (Game::key.keycode.UP && PF->isOnGround)
        {
            PF->ApplyForce(-250, Vector2::AY);
        }
        if (Game::key.keycode.DOWN)
        {
            PF->ApplyForce(400, Vector2::AY);
        }
        if (Base->getComponent<Collider>()->isColliding)
        {
            v++;
            Base->getComponent<PlatformPhysics>()->Disable();
            Base->transform->Acceleration.Y = 0;
            Base->transform->velocity.Y = 0;
            Base->GetSprite()->SetupAnimation(0, 0, 500);
            died = true;
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