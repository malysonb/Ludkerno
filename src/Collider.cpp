#include "../include/Components/Collider.hpp"
#include "../include/Entity.hpp"

void Collider::Init()
{
    if (!Active)
    {
        Active = true;
        m_BoxCollider = &Base->GetSprite()->destRect;
        L = m_BoxCollider->x;
        R = m_BoxCollider->x + m_BoxCollider->w;
        T = m_BoxCollider->y;
        B = m_BoxCollider->y + m_BoxCollider->h;
    }
    else
    {
        Debug::log("you can't to initialize an active component!", Debug::WARN);
    }
}

void Collider::Update()
{
    L = m_BoxCollider->x;
    R = m_BoxCollider->x + m_BoxCollider->w;
    T = m_BoxCollider->y;
    B = m_BoxCollider->y + m_BoxCollider->h;
}