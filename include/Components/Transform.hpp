#pragma once
#include "../Game.hpp"
#include "../Component.hpp"

class Transform : public Component
{
    public:
    Transform();
    struct Vector2
    {
        float X = 0, Y = 0;
    };

    Vector2 position, velocity;

    void Update();
    void Render();
    const char* GetName() {return "Transform";}
    void Move(float XA, float YA);
    void SetPosition(float XA, float YA);
};