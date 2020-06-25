#pragma once
#include "../Game.hpp"
#include "../Component.hpp"

class Transform : public Component
{
    public:
    Transform()
    {
        Active = true;
        position.X = 0;
        position.Y = 0;
    }

    struct Vector2
    {
        float X = 0, Y = 0;
    };

    Vector2 position, velocity;

    void Update()
    {
        position.X += velocity.X;
        position.Y += velocity.Y;
    }

    void Render()
    {
        /* Not Implemented */
    }

    const char* GetName() {return "Transform";}

    void SetPosition(float XA, float YA)
    {
        position.X = XA;
        position.Y = YA;
    }

};