#pragma once

#include "Game.hpp"
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
        middle.X = static_cast<float>(Game::screen.DynamicHPosition(50));
        middle.Y = static_cast<float>(Game::screen.DynamicVPosition(50));
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
            if (relativePosition.Y + velocity >= Game::matrix.Y)
                relativeVelocity.Y = (velocity);
            else relativeVelocity.Y = 0;
        }
    }
};