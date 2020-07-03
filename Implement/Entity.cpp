#include "../include/Entity.hpp"
#include "../include/TextureMngr.hpp"
#include "../include/Debug.hpp"
#include "../include/Component.hpp"

//Sprite *sprite;

/**
 * Instantiate an Entity.
 * @param texturePath path of the spritesheet.
 * @param Size_x or @param Size_y default size of the sprite.
 * @param n_ofAnimations number of rows in the spritesheet.
 */
Entity::Entity(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations)
{
    transform = new Transform();
    AddComponent<Sprite>();
    m_mySprite = getComponent<Sprite>();
    m_mySprite->Init(texturePath, Size_x, Size_y, n_ofAnimations);
    m_mySprite->SetupAnimation(0, 1, 500);
}

Entity::~Entity()
{
    Debug::log("Entities also dies...", Debug::INFO);
}

void Entity::SetSprite(const char *path)
{
    m_mySprite->LoadSpritesheet(TextureMngr::LoadTexture(path));
}

Sprite *Entity::GetSprite()
{
    return m_mySprite;
}

void Entity::Update()
{
    transform->Update();
    m_mySprite->destRect.x = (transform->position.X);
    m_mySprite->destRect.y = (transform->position.Y);
    m_mySprite->destRect.h = m_mySprite->srcRect.h * transform->scale.Y;
    m_mySprite->destRect.w = m_mySprite->srcRect.w * transform->scale.X;
    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active){
            myComponents[i]->Update();
        }
    }
}

void Entity::SetPosition(int x, int y)
{
    transform->SetPosition(x,y);
}

//https://www.youtube.com/watch?v=pWZS1MtxI-A

void Entity::Render()
{
    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active)
            myComponents[i]->Render();
    }
}
