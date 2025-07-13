#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * ONBOARD COMPONENT!!
 */
#include "Component.hpp"
#include "Vector2.hpp"

class Collider : public Component
{
private:
    SDL_Rect *m_BoxCollider;
    Component *LastCollider = nullptr;
    int ID;
    
public:
    bool isColliding = false;
    float L, R, T, B;
    Vector2 colDirection; // Direção da colisão

    // Constructor to initialize Collider with bounds
    Collider(){
        L = 0;
        R = 0;
        T = 0;
        B = 0;
    }

    Collider(float left, float right, float top, float bottom)
        : L(left), R(right), T(top), B(bottom) {}

    void Init();
    void Update();
    void Render()
    {
        /* TODO */
    }

    const char *GetName()
    {
        return "Collider";
    }

    ~Collider()
    {

    }
};