#pragma once
#include "../Component.hpp"

class Collider : public Component
{
private:
    SDL_Rect m_BoxCollider;
public:

    bool isColliding = false;

    void Init(int x, int y, int h, int w)
    {
        if(!Active)
        {
            Active = true;
            m_BoxCollider.x = x;
            m_BoxCollider.y = y;
            m_BoxCollider.h = h;
            m_BoxCollider.w = w;
        }
        else
        {
            Debug::log("",Debug::WARN);
        }
        
    }

    void Update()
    {
        /* TODO */
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