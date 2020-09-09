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
    int V_Limit = 500;

    void Init()
    {
        Active = true;
    }
    void Update()
    {
        float value = gravity/(1/static_cast<float>(Game::FrameRate));
        gravity = (static_cast<int>(value) * 1/Game::FrameRate);
        ForceY += (mass/gravity);
        ForceY >= V_Limit ? ForceY = V_Limit : ForceY;
        Base->transform->velocity.Y = static_cast<float>(ForceY);
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
            ForceY = intensity;
        }
        if (Axis == Vector2::AX)
        {
            ForceX = intensity;
        }
    }
};