#pragma once
#include "../Component.hpp"
#include "../Entity.hpp"

class PlatformPhysics : public Component
{
public:
    bool isOnGround = true;
    float ForceX = 0, ForceY = 0;
    float gravity = 1;
    float mass = 1;
    float V_Limit = 10;
    bool forceApplied = false;

    void Init()
    {
        Active = true;
    }
    void Update()
    {
        float G = gravity, M = mass;
        ForceY += (G*M) * Game::DeltaTime/30;
        ForceY >= V_Limit ? ForceY = V_Limit : ForceY;
        if(!forceApplied)
        {
            if(isOnGround)
                ForceY = 0;
        }
        else
        {
            forceApplied = false;
        }
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
    
    void ApplyForce(float intensity, Vector2::Vector Axis)
    {
        if (Axis == Vector2::AY)
        {
            ForceY += intensity;
        }
        if (Axis == Vector2::AX)
        {
            ForceX += intensity;
        }
        forceApplied = true;
    }
};