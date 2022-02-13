#pragma once
#include "../LudkernoLib.hpp"
#include "Cena.hpp"
#include "Cactus.hpp"
#include "Generator.hpp"

class Input : public Component
{
public:
    Transform *transform = nullptr;
    PlatformPhysics *PF = nullptr;
    void Init()
    {
        Active = true;
        transform = Base->transform;
        Debug::log("Initializing Input", Debug::INFO);
        PF = Base->getComponent<PlatformPhysics>();
        PF->mass = 5;
    }
    bool died = false;
    const char *GetName() { return "Input"; }
    bool able = true;
    bool onTop = false;
    int v = 0;
    float ForceJump = -2.2f;
    void Update()
    {
        if (transform->GetScreenPosition().Y >= Ludkerno::screen.DynamicVPosition(50))
        {
            able = true;
            onTop = false;
            PF->isOnGround = true;
            transform->SetScreenPosition(static_cast<int>(transform->GetScreenPosition().X), Ludkerno::screen.DynamicVPosition(50));
        }
        else
        {
            PF->isOnGround = false;
        }
        if ((Ludkerno::key.keycode.UP || Ludkerno::key.keycode.LEFT_CLICK) && PF->isOnGround)
        {
            PF->ApplyForce(ForceJump, Vector2::AY);
        }
        if (Ludkerno::key.keycode.DOWN)
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
        /*transform->velocity.Y = Ludkerno::key.keycode.Y_Axis * 2;
        transform->velocity.X = Ludkerno::key.keycode.X_Axis * 2;
        if(transform->position.X >= Ludkerno::camera->middle.X)
        {
            Ludkerno::camera->Move(Vector2::AX, transform->velocity.X);
        }
        if(transform->position.Y >= Ludkerno::camera->middle.Y)
        {
            Ludkerno::camera->Move(Vector2::AY, transform->velocity.Y);
        }*/
    }

    void Render()
    {
        /*Not Implemented*/
    }
};