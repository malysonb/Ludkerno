#pragma once
#include "../Ludkerno.hpp"
#include "../include/Utils.hpp"

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
        Base->getComponent<PlatformPhysics>()->mass = 5;
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
                Base->transform->velocity.X = -2 * Game::DeltaTime;
            }
            if (Game::key.keycode.RIGHT && !Game::key.keycode.LEFT)
            {
                Base->GetSprite()->flipHorizontally(false);
                Base->transform->velocity.X = 2 * Game::DeltaTime;
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
            Base->getComponent<PlatformPhysics>()->ApplyForce(-3, Vector2::AY);
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
        bool cap = false;
        for (int row = 0; row < Game::GetScene()->M_SceneRows; row++)
        {
            for (int col = 0; col < Game::GetScene()->M_SceneCols; col++)
            {
                if (Game::GetScene()->map[row][col] != 4)
                {
                    if(Utils::IsBetween(static_cast<int>(Base->transform->GetPosition().X), (16 * col), (16 * col)+16))
                    {
                        if(Utils::IsBetween(static_cast<int>(Base->transform->GetPosition().Y-1), (16 * row), (16 * row)+16))
                        {
                            cap = true;
                            isGrounded = true;
                            Base->getComponent<PlatformPhysics>()->isOnGround = true;
                            Base->transform->SetScreenPosition(Base->transform->GetScreenPosition().X, Base->transform->GetScreenPosition().Y - Base->transform->velocity.Y);
                        }
                    }
                }
            }
        }
        if (!cap)
        {
            isGrounded = false;
            Base->getComponent<PlatformPhysics>()->isOnGround = false;
        }
        if (Base->transform->velocity.X != 0)
        {
            if(Base->transform->GetScreenPosition().X >= Game::screen.DynamicHPosition(50))
                Game::camera->Move(Vector2::AX, Base->transform->velocity.X);
        }
        else
        {
            Game::camera->Move(Vector2::AX, 0);
        }
    }
    void Render()
    {
    }
    const char *GetName() { return "PlatformerInput"; }
};