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

    void Move(Vector2::Vector Axis, int velocity)
    {
        if(Axis == Vector2::AX)
        {
            if (relativePosition.X + velocity >= Game::matrix.X)
                relativeVelocity.X = static_cast<float>(velocity);
            else relativeVelocity.X = 0;
        }
        if(Axis == Vector2::AY)
        {
            if (relativePosition.Y + velocity >= Game::matrix.Y)
                relativeVelocity.Y = static_cast<float>(velocity);
            else relativeVelocity.Y = 0;
        }
    }
};