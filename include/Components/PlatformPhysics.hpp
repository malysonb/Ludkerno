#pragma once
#include "../Component.hpp"
#include "../Entity.hpp"
#include <algorithm>

class PlatformPhysics : public Component
{
public:
    bool isOnGround = true;
    float AccelX = 0, AccelY = 0;
    float gravity = 1;
    float mass = 1;
    float V_LimitY = 10;
    float V_LimitX = 2;
    bool forceApplied = false;

    ~PlatformPhysics()
    {

    }

    void Init()
    {
        Active = true;
    }
    void Update()
    {
        float G = gravity, M = mass;

        AccelY += (G * M) * Ludkerno::DeltaTime / 30;

        if (!forceApplied && Base->getComponent<Collider>() != NULL && Base->getComponent<Collider>()->isColliding)
        {
            if(Base->getComponent<Collider>()->colDirection.Y < 0)
            {
                if(Base->getComponent<Collider>()->colDirection.X == 0)
                    isOnGround = true;
                AccelY += -AccelY; // Inverte a direção da força aplicada
            }
            AccelX += Base->getComponent<Collider>()->colDirection.X*0.1f; // Inverte a direção da força aplicada
        }
        else
        {
            isOnGround = false;
            forceApplied = false; // Reseta a força aplicada após o movimento
        }

        AccelY = std::clamp(AccelY, -V_LimitY, V_LimitY); // Limitação de velocidade
        AccelX = std::clamp(AccelX, -V_LimitX, V_LimitX); // Limitação de velocidade
        Base->transform->velocity.Y = AccelY;
        Base->transform->velocity.X = AccelX; // Atualiza a velocidade na direção X
    }
    void Render()
    {
        /*Nothing to Renderize*/
    }

    const char *GetName()
    {
        return "PlatformPhysics";
    }
    
    void ApplyForce(float intensity, Vector2::Vector Axis)
    {
        if (Axis == Vector2::AY)
        {
            AccelY += intensity;
        }
        if (Axis == Vector2::AX)
        {
            AccelX += intensity;
        }
        forceApplied = true;
    }
};