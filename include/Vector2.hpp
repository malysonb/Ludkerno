#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * Simple vector code.
 */
#include "Game.hpp"

struct Vector2
{
    enum Vector{ AX, AY };

    float X = 0, Y = 0;

    Vector2();

    Vector2(float x,float  y);


    float Length();
    float DotProduct(Vector2 *vector2);
    Vector2 Direction();
    static Vector2 Direction(Vector2 *vector2);
    Vector2 Normal();

    Vector2 operator+(Vector2& vector2);
    Vector2 operator+(Vector2* vector2);
    Vector2 operator-(Vector2& vector2);
    Vector2 operator-(Vector2* vector2);
    Vector2 operator/(Vector2& vector2);
    Vector2 operator/(float value);
    Vector2 operator*(float value);
    void operator-=(Vector2& vector2);
    bool operator==(Vector2& vector2);
    bool operator!=(Vector2& vector2);
    bool operator>(Vector2& vector2);
    bool operator>=(Vector2& vector2);
    bool operator<=(Vector2& vector2);

    static Vector2 Identity;
};