#pragma once
#include "../Component.hpp"
#include "../Entity.hpp"

class PlatformPhysics : public Component
{
public:
    bool isOnGround = true;
    int ForceX = 0, ForceY = 0;
    int gravity = 10;
    int mass = 40;

    void Init()
    {
        Active = true;
    }
    void Update()
    {
        gravity = gravity * Game::FrameRate;
        gravity = 600 * 1/Game::FrameRate;
        ForceY += (mass/gravity);
        ForceY >= 240 ? ForceY = 240 : ForceY;
        Base->transform->velocity.Y = ForceY;
    }
    void Render()
    {
        /*Nothing to Renderize*/
    }
    const char *GetName()
    {
        return "PlatformPhysics";
    }
    void ApplyForce(int intensity, Vector2::Vector Axis)
    {
        if (Axis == Vector2::AY)
        {
            ForceY = (intensity);
        }
        if (Axis == Vector2::AX)
        {
            ForceX = (intensity);
        }
    }
};