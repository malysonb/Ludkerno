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
        int G = gravity, M = mass;
        M = mass * 60;
        G = gravity * 60;
        M = M / Game::FrameRate;
        G = G / Game::FrameRate;
        ForceY += (M/G);
        ForceY >= V_Limit ? ForceY = V_Limit : ForceY;
        //printf("ForceY: %d\n",ForceY);

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