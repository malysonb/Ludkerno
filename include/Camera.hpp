#pragma once

#include "Ludkerno.hpp"
#include "Transform.hpp"
#include "Screen.hpp"
#include "Utils.hpp" // Include the header file for Utils

class Camera
{
private:
public:
    Vector2 relativePosition = {0, 0}; // Inicialização
    Vector2 relativeVelocity = {0, 0}; // Inicialização
    Vector2 middle;
    bool canMove = false;

    void Init()
    {
        middle.X = static_cast<float>(Ludkerno::screen.DynamicHPosition(50));
        middle.Y = static_cast<float>(Ludkerno::screen.DynamicVPosition(50));
        relativePosition = {0, 0}; // Garantir inicialização
        relativeVelocity = {0, 0}; // Garantir inicialização
    }

    void Update()
    {
        if (canMove) // Verificar se a câmera pode se mover
        {
            relativePosition = relativePosition + relativeVelocity;
        }
        middle.X = static_cast<float>(Ludkerno::screen.DynamicHPosition(50)) - relativePosition.X;
        middle.Y = static_cast<float>(Ludkerno::screen.DynamicVPosition(50)) - relativePosition.Y;
    }

    Vector2 &GetCameraPos()
    {
        return relativePosition;
    }

    Vector2 &GetMiddle()
    {
        return middle;
    }

    void Move(const Vector2 &velocity)
    {
        if (canMove) // Verificar se a câmera pode se mover
        {
            relativeVelocity = velocity;
        }
    }

    void Follow(Transform *target, Vector2 offset = Vector2::Zero, float speed = 0.1f)
    {
        if (target != nullptr)
        {
            relativePosition.X = Utils::Lerp(relativePosition.X, target->position.X - Ludkerno::screen.DynamicHPosition(50) + offset.X, speed);
            relativePosition.Y = Utils::Lerp(relativePosition.Y, target->position.Y - Ludkerno::screen.DynamicVPosition(50) + offset.Y, speed);
            //relativePosition.X = target->position.X - Ludkerno::screen.DynamicHPosition(50);
            //relativePosition.Y = target->position.Y - Ludkerno::screen.DynamicVPosition(50);
        }
    }
};