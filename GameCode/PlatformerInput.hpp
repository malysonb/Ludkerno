#pragma once
#include "../LudkernoLib.hpp"
#include "../include/Utils.hpp"

class PlatformerInput : public Component
{
public:
    bool isGrounded = false;
    int PowerJump = -150;

    // Constructor
    void Init()
    {
        Active = true;
        Base->AddComponent<PlatformPhysics>(Base);
        Base->getComponent<PlatformPhysics>()->Init();
        Base->getComponent<PlatformPhysics>()->isOnGround = false;
        Base->getComponent<PlatformPhysics>()->mass = 5;
    }
    // Loop Update
    void Update()
    {
        PlatformPhysics *phys = Base->getComponent<PlatformPhysics>();
        Collider *col = Base->getComponent<Collider>();
        // Movimentação horizontal
        if (Ludkerno::key.keycode.RIGHT || Ludkerno::key.keycode.LEFT)
        {
            if (Base->GetSprite()->getCurrentAnim() != 1 && phys->isOnGround)
            {
                Base->GetSprite()->SetAnimation(1); // Andando
            }else if(Base->GetSprite()->getCurrentAnim() != 2 && !phys->isOnGround){
                Base->GetSprite()->SetAnimation(2); // Idle no ar
            }
            if (Ludkerno::key.keycode.LEFT && !Ludkerno::key.keycode.RIGHT)
            {
                if(col->colDirection.X == 0)
                    phys->AccelX += -.2f * Ludkerno::DeltaTime; // Aumenta a aceleração
            }
            if (Ludkerno::key.keycode.RIGHT && !Ludkerno::key.keycode.LEFT)
            {
                if(col->colDirection.X == 0)
                    phys->AccelX += .2f * Ludkerno::DeltaTime; // Aumenta a aceleração
            }
            if(phys->AccelX > 0){
                Base->GetSprite()->flipHorizontally(false);
            }
            if(phys->AccelX < 0){
                Base->GetSprite()->flipHorizontally(true);
            }
        }
        else
        {
            // Desaceleração horizontal
            if(phys->isOnGround){ // Desaceleração no chão
                if (Base->GetSprite()->getCurrentAnim() != 0)
                {
                    Base->GetSprite()->SetAnimation(0); // Idle
                }
                phys->AccelX *= 0.9f;
            }else{ // Desaceleração no ar
                if(Base->GetSprite()->getCurrentAnim() != 2)
                    Base->GetSprite()->SetAnimation(2); // Idle no ar
                phys->AccelX *= 0.999f; // Aumenta a desaceleração no ar
            }
        }

        // Pulo
        if (Ludkerno::key.keycode.UP && Base->getComponent<PlatformPhysics>()->isOnGround)
        {
            Base->getComponent<PlatformPhysics>()->ApplyForce(-3, Vector2::AY); // Intensidade do pulo ajustada
        }

        Vector2 offset(0,-Ludkerno::screen.DynamicVPosition(20));
        Ludkerno::camera->Follow(Base->transform, offset, 0.1f);

        // Teletransporte com clique do mouse
        if (Ludkerno::key.keycode.LEFT_CLICK)
        {
            Base->getComponent<PlatformPhysics>()->AccelY = 0;
            Base->transform->velocity = Vector2::Zero;
            Base->transform->SetPosition(Ludkerno::key.keycode.MouseX - Ludkerno::matrix.X, Ludkerno::key.keycode.MouseY - Ludkerno::matrix.Y);
        }
        if (Ludkerno::key.keycode.QUIT)
        {
            Ludkerno::StopLudkerno();
        }
    }
    // Render
    void Render()
    {
    }
    const char *GetName() { return "PlatformerInput"; }
};