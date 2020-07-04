#pragma once
#include "../Game.hpp"
#include "../Component.hpp"

struct Vector2
{
    float X = 0, Y = 0;
    Vector2()
    {
        X = 0;
        Y = 0;
    }
    Vector2(int x, int y)
    {
        X = x;
        Y = y;
    }
    Vector2 operator+(Vector2& vector2)
    {
        Vector2 result;
        result.X = this->X + vector2.X;
        result.Y = this->Y + vector2.Y;
        return result;
    }
    Vector2 operator-(Vector2& vector2)
    {
        Vector2 result;
        result.X = this->X - vector2.X;
        result.Y = this->Y - vector2.Y;
        return result;
    }
    void operator-=(Vector2& vector2)
    {
        this->X - vector2.X;
        this->Y - vector2.Y;
    }

    bool operator==(Vector2& vector2)
    {
        if(this->X == vector2.X && this->Y == vector2.Y)
        {
            return true;
        }
        else return false;
    }

    bool operator!=(Vector2& vector2)
    {
        if(this->X != vector2.X && this->Y != vector2.Y)
        {
            return true;
        }
        else return false;
    }
    bool operator>(Vector2& vector2)
    {
        if(this->X > vector2.X && this->Y > vector2.Y)
        {
            return true;
        }
        else return false;
    }
    bool operator>=(Vector2& vector2)
    {
        if(this->X >= vector2.X && this->Y >= vector2.Y)
        {
            return true;
        }
        else return false;
    }

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
    }

    void SetSize(float XA, float YA)
    {
        scale.X = XA;
        scale.Y = YA;
    }
};