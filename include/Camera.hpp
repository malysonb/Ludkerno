#pragma once

#include "Game.hpp"
#include "Components/Transform.hpp"
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
        middle.X = Game::screen.DynamicHPosition(50);
        middle.Y = Game::screen.DynamicVPosition(50);
    }
    void Update()
    {
        relativePosition = relativePosition + relativeVelocity;
    }

    void Move(Vector2::Vector Axis, float velocity)
    {
        if(Axis == Vector2::AX)
        {
            if (relativePosition.X + velocity >= Game::matrix.X)
                relativeVelocity.X = velocity;
            else relativeVelocity.X = 0;
        }
        if(Axis == Vector2::AY)
        {
            if (relativePosition.Y + velocity >= Game::matrix.Y)
                relativeVelocity.Y = velocity;
            else relativeVelocity.Y = 0;
        }
    }

    /*void Move(int X, int Y)
    {
        if (relativePosition.X + X >= Game::matrix.X && X != 0)
        {
            relativeVelocity.X = X;
        }
        else if (Game::matrix.X > 0)
        {
            relativeVelocity.X = 0;
        }
        else
        {
            relativeVelocity.X = 0;
        }
        if (relativePosition.Y + Y >= Game::matrix.Y && Y != 0)
        {
            relativeVelocity.Y = Y;
        }
        else if (Game::matrix.Y > 0)
        {
            relativeVelocity.Y = 0;
        }
        else
        {
            relativeVelocity.Y = 0;
        }
    }*/
};