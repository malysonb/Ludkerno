#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * Transform code for every entity.
 */
#include "Game.hpp"
#include "Component.hpp"
#include "Vector2.hpp"

struct Vector2;

class Transform : public Component
{
public:
    Transform()
    {
        Active = true;
        position.X = 0;
        position.Y = 0;
        Acceleration.X = 0;
        Acceleration.Y = 0;
        velocity.X = 0;
        velocity.Y = 0;
        scale.X = 1;
        scale.Y = 1;
    }
    ~Transform()
    {
        
    }

    Vector2 position, scale, velocity, Acceleration;

    void Update()
    {
        //Acceleration = Acceleration * 1/Game::FrameRate;
        //velocity = velocity * Game::FrameRate;
        velocity = velocity * 1/Game::FrameRate;
        position = position - Game::camVelocity;
        position = position + velocity;
    }

    void Render()
    {
        /* Not Implemented */
    }

    const char *GetName() { return "Transform"; }

    void SetPosition(float XA, float YA)
    {
        position.X = XA;
        position.Y = YA;
        position = position - Game::matrix;
    }

    Vector2 GetPosition()
    {
        Vector2 temp;
        temp.X = position.X - Game::matrix.X;
        temp.Y = position.Y - Game::matrix.Y;
        return temp;
    }
    Vector2 GetScreenPosition()
    {
        return position;
    }

    void SetScreenPosition(float XA, float YA)
    {
        position.X = XA;
        position.Y = YA;
    }

    void SetSize(float XA, float YA)
    {
        scale.X = XA;
        scale.Y = YA;
    }
};