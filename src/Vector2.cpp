#include "../include/Vector2.hpp"
#include <cmath>

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

float Vector2::Length()
{
    return sqrt((this->X * this->X) + (this->Y * this->Y));
}

float Vector2::DotProduct(Vector2 *direction)
{
    return (this->X * direction->X) + (this->Y * direction->Y);
}

Vector2 Vector2::Direction()
{
    Vector2 direction(0,0);
    if(this->Length() == 0)
        return direction;
    direction.X = this->X/this->Length();
    direction.Y = this->Y/this->Length();
    return direction;
}

Vector2 Vector2::Direction(Vector2 *vector2)
{
    Vector2 direction(0,0);
    if(vector2->Length() == 0)
        return direction;
    direction.X = vector2->X/vector2->Length();
    direction.Y = vector2->Y/vector2->Length();
    return direction;
}

Vector2 Vector2::Normal()
{
    Vector2 normal(-this->Y, this->X);
    return normal;
}

Vector2 Vector2::operator+(Vector2 &vector2)
{
    Vector2 result;
    result.X = this->X + vector2.X;
    result.Y = this->Y + vector2.Y;
    return result;
}
Vector2 Vector2::operator+(Vector2 *vector2)
{
    Vector2 result;
    result.X = this->X + vector2->X;
    result.Y = this->Y + vector2->Y;
    return result;
}
Vector2 Vector2::operator-(Vector2 &vector2)
{
    Vector2 result;
    result.X = this->X - vector2.X;
    result.Y = this->Y - vector2.Y;
    return result;
}
Vector2 Vector2::operator-(Vector2 *vector2)
{
    Vector2 result;
    result.X = this->X - vector2->X;
    result.Y = this->Y - vector2->Y;
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