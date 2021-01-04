#include "../include/Vector2.hpp"

float X = 0, Y = 0;
Vector2::Vector2()
{
    X = 0;
    Y = 0;
}
Vector2::Vector2(float x, float y)
{
    this->X = x;
    this->Y = y;
}
Vector2 Vector2::operator+(Vector2 &vector2)
{
    Vector2 result;
    result.X = this->X + vector2.X;
    result.Y = this->Y + vector2.Y;
    return result;
}
Vector2 Vector2::operator-(Vector2 &vector2)
{
    Vector2 result;
    result.X = this->X - vector2.X;
    result.Y = this->Y - vector2.Y;
    return result;
}
Vector2 Vector2::operator*(float value)
{
    Vector2 result;
    result.X = this->X * value;
    result.Y = this->Y * value;
    return result;
}
Vector2 Vector2::operator/(Vector2 &vector2)
{
    Vector2 result;
    result.X = this->X / vector2.X;
    result.Y = this->Y / vector2.Y;
    return result;
}
Vector2 Vector2::operator/(float value)
{
    Vector2 result;
    result.X = this->X / value;
    result.Y = this->Y / value;
    return result;
}
void Vector2::operator-=(Vector2 &vector2)
{
    this->X -= vector2.X;
    this->Y -= vector2.Y;
}

bool Vector2::operator==(Vector2 &vector2)
{
    if (this->X == vector2.X && this->Y == vector2.Y)
    {
        return true;
    }
    else
        return false;
}

bool Vector2::operator!=(Vector2 &vector2)
{
    if (this->X != vector2.X && this->Y != vector2.Y)
    {
        return true;
    }
    else
        return false;
}
bool Vector2::operator>(Vector2 &vector2)
{
    if (this->X > vector2.X && this->Y > vector2.Y)
    {
        return true;
    }
    else
        return false;
}

bool Vector2::operator>=(Vector2 &vector2)
{
    if (this->X >= vector2.X && this->Y >= vector2.Y)
    {
        return true;
    }
    else
        return false;
}

bool Vector2::operator<=(Vector2 &vector2)
{
    if (this->X <= vector2.X && this->Y <= vector2.Y)
    {
        return true;
    }
    else
        return false;
}