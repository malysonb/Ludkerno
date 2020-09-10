#pragma once
#include "../Ludkerno.hpp"

class PlatformerInput : public Component
{
public:
    bool isGrounded = false;
    int PowerJump = -150;
    
    void Init()
    {
        Active = true;
        Base->AddComponent<PlatformPhysics>(Base);
        Base->getComponent<PlatformPhysics>()->Init();
        Base->getComponent<PlatformPhysics>()->isOnGround = false;
    }
    void Update()
    {
        if (Game::key.keycode.RIGHT || Game::key.keycode.LEFT)
        {
            if (Base->GetSprite()->getCurrentAnim() == 0)
            {
                Base->GetSprite()->SetAnimation(1);
            }
            if (Game::key.keycode.LEFT && !Game::key.keycode.RIGHT)
            {
                Base->GetSprite()->flipHorizontally(true);
                Base->transform->velocity.X = (-120 * 60)/static_cast<float>(Game::FrameRate);
            }
            if (Game::key.keycode.RIGHT && !Game::key.keycode.LEFT)
            {
                Base->GetSprite()->flipHorizontally(false);
                Base->transform->velocity.X = (120 * 60)/static_cast<float>(Game::FrameRate);
            }
        }
        else
        {
            if (Base->GetSprite()->getCurrentAnim() == 1)
            {
                Base->GetSprite()->SetAnimation(0);
            }
            Base->transform->velocity.X = 0;
        }
        if (Game::key.keycode.UP && isGrounded)
        {
            Base->getComponent<PlatformPhysics>()->ApplyForce(-150, Vector2::AY);
            isGrounded = false;
            //Base->getComponent<PlatformPhysics>()->isOnGround = false;
        }
        if (Base->transform->GetScreenPosition().Y >= Game::screen.DynamicVPosition(100))
        {
            isGrounded = true;
            Base->getComponent<PlatformPhysics>()->isOnGround = true;
            Base->transform->velocity.Y = 0;
            Base->transform->SetScreenPosition(static_cast<int>(Base->transform->GetScreenPosition().X), Game::screen.DynamicVPosition(100));
        }
    }
    void Render()
    {
    }
    const char *GetName() { return "PlatformerInput"; }
};