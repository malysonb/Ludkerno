#include "../include/Entity.hpp"
#include "../include/Components/Collider.hpp"

//Sprite *sprite;

/**
 * Instantiate an Entity.
 * @param texturePath path of the spritesheet.
 * @param Size_x or @param Size_y default size of the sprite.
 * @param n_ofAnimations number of rows in the spritesheet.
 */
Entity::Entity()
{
    transform = new Transform();
    m_mySprite = nullptr;
}

Entity::~Entity()
{
    delete transform;
}

void Entity::SetSprite(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations)
{
    AddComponent<Sprite>(this);
    m_mySprite = getComponent<Sprite>();
    m_mySprite->Init(texturePath, Size_x, Size_y, n_ofAnimations);
    m_mySprite->SetupAnimation(0, 1, 500);
    m_mySprite->destRect.x = static_cast<int>(transform->position.X) - static_cast<int>(m_mySprite->OriginPoint.X);
    m_mySprite->destRect.y = static_cast<int>(transform->position.Y) - static_cast<int>(m_mySprite->OriginPoint.Y);
    m_mySprite->destRect.h = m_mySprite->srcRect.h * static_cast<int>(transform->scale.Y);
    m_mySprite->destRect.w = m_mySprite->srcRect.w * static_cast<int>(transform->scale.X);
}

Sprite *Entity::GetSprite()
{
    return getComponent<Sprite>();
}

Vector2 Vector2::Identity;

void Entity::Update()
{
    //transform->position = transform->position - Game::camVelocity;
    transform->Update();
    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active)
        {
            myComponents[i]->Update();
        }
    }
    if (m_mySprite != nullptr)
    {
        m_mySprite->destRect.x = static_cast<int>(transform->position.X) - static_cast<int>(m_mySprite->OriginPoint.X);
        m_mySprite->destRect.y = static_cast<int>(transform->position.Y) - static_cast<int>(m_mySprite->OriginPoint.Y);
        m_mySprite->destRect.h = m_mySprite->srcRect.h * static_cast<int>(transform->scale.Y);
        m_mySprite->destRect.w = m_mySprite->srcRect.w * static_cast<int>(transform->scale.X);
    }
}

void Entity::SetPosition(float x, float y)
{
    transform->SetPosition(x, y);
}

//https://www.youtube.com/watch?v=pWZS1MtxI-A

void Entity::Render()
{
    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active)
            myComponents[i]->Render();
    }
    if (getComponent<Collider>() != nullptr && getComponent<Collider>()->isColliding)
    {
        SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(Game::renderer, &m_mySprite->destRect);
    }
}
