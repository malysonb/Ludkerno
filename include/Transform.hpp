#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * Transform code for every entity.
 */
#include "Ludkerno.hpp"
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

    void Init() override
    {
        Active = true;
    }

    Vector2 position, scale, velocity, Acceleration;

    void Update()
    {
        position = position + velocity; // Atualizar posição global
        //std::cout << "Global Position: " << position.X << " " << position.Y << std::endl;
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

    Vector2 GetPosition()
    {
        return position; // Retorna a posição global
    }

    void SetPosition(Vector2 pos)
    {
        position.X = pos.X;
        position.Y = pos.Y;
    }

    void SetScale(float XA, float YA)
    {
        scale.X = XA;
        scale.Y = YA;
    }

    Vector2 GetScreenPosition()
    {
        // Calcula a posição relativa à matriz
        return position + Ludkerno::matrix;
    }

    void SetToScreenPosition(int XA, int YA)
    {
        position.X = static_cast<float>(XA) + Ludkerno::matrix.X;
        position.Y = static_cast<float>(YA) + Ludkerno::matrix.Y;
    }

    void SetToScreenPosition(float XA, float YA)
    {
        position.X = XA + Ludkerno::matrix.X;
        position.Y = YA + Ludkerno::matrix.Y;
    }

    void SetSize(int XA, int YA)
    {
        scale.X = static_cast<float>(XA);
        scale.Y = static_cast<float>(YA);
    }

};