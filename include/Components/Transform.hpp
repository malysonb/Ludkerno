#pragma once
#include "../Game.hpp"
#include "../Component.hpp"

struct Vector2
{

    enum Vector{ AX, AY };

    float X = 0, Y = 0;
    Vector2();

    Vector2(int x, int y);

    Vector2 operator+(Vector2& vector2);
    Vector2 operator-(Vector2& vector2);
    Vector2 operator/(Vector2& vector2);
    Vector2 operator/(float value);
    void operator-=(Vector2& vector2);
    bool operator==(Vector2& vector2);
    bool operator!=(Vector2& vector2);
    bool operator>(Vector2& vector2);
    bool operator>=(Vector2& vector2);

    static Vector2 Identity;
};

class Transform : public Component
{
public:
    Transform()
    {
        Active = true;
        position.X = 0;
        position.Y = 0;
        velocity.X = 0;
        velocity.Y = 0;
        scale.X = 1;
        scale.Y = 1;
    }

    Vector2 position, scale, velocity;

    void Update()
    {
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