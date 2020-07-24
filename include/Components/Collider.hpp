#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * ONBOARD COMPOENT!!
 */
#include "../Component.hpp"

class Collider : public Component
{
private:
public:
    SDL_Rect *m_BoxCollider;
    Component *LastCollider = nullptr;
    bool isColliding = false;
    int ID;
    int L = 0, R = 0, T = 0, B = 0;

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
};