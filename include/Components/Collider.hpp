#pragma once
#include "../Component.hpp"

class Collider : public Component
{
private:
public:
    SDL_Rect m_BoxCollider;
    Component *LastCollider = nullptr;
    bool isColliding = false;
    int ID;
    int L, R, T, B;

    void Init()
    {
        if(!Active)
        {
            Active = true;
            m_BoxCollider = Base->GetSprite()->destRect;
            L = m_BoxCollider.x;
            R = m_BoxCollider.x + m_BoxCollider.w;
            T = m_BoxCollider.y;
            B = m_BoxCollider.y + m_BoxCollider.h;
        }
        else
        {
            Debug::log("you cant to initialize again",Debug::WARN);
        }
    }

    void Update()
    {

    }

    void Render()
    {
        /* TODO */
    }

    const char* GetName()
    {
        return "Collider";
    }
};