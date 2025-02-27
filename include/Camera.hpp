#pragma once

#include "Ludkerno.hpp"
#include "Transform.hpp"
#include "Screen.hpp"

class Camera
{
private:
public:
    Vector2 relativePosition;
    Vector2 relativeVelocity;
    Vector2 middle;
    bool canMove = false;

    void Init()
    {
        middle.X = static_cast<float>(Ludkerno::screen.DynamicHPosition(50));
        middle.Y = static_cast<float>(Ludkerno::screen.DynamicVPosition(50));
    }
    void Update()
    {
        relativePosition = relativePosition + relativeVelocity;
    }

    Vector2 &GetCameraPos()
    {
        return relativePosition;
    }

    void Move(Vector2::Vector Axis, float velocity)
    {
        if(Axis == Vector2::AX)
        {
            relativeVelocity.X = (velocity);
        }
        if(Axis == Vector2::AY)
        {
            relativeVelocity.Y = (velocity);
        }
    }
};