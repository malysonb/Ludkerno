#pragma once
#include "../Component.hpp"
#include "../Entity.hpp"

class PlatformPhysics : public Component
{
public:
    bool isOnGround = true;
    int ForceX = 0, ForceY = 0;
    int gravity = 10;
    int mass = 10;

    void Init()
    {
        Active = true;
    }
    void Update()
    {
        Base->transform->Acceleration.Y = (isOnGround ? ForceY*gravity : gravity)/mass;
        Base->transform->velocity.Y = isOnGround ? 0 : Base->transform->velocity.Y;
        Base->transform->velocity.Y = Base->transform->velocity.Y <= -10 ? -10 : Base->transform->velocity.Y;
        Base->transform->velocity.Y = Base->transform->velocity.Y >= 4 ? 4 : Base->transform->velocity.Y;
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