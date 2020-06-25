#include "../include/Entity.hpp"
#include "../include/TextureMngr.hpp"
#include "../include/Debug.hpp"
#include "../include/Component.hpp"

Sprite *sprite;

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
    sprite = getComponent<Sprite>();
    sprite->Init(texturePath, Size_x, Size_y, n_ofAnimations);
    transform->SetPosition(400, 300);
    sprite->SetupAnimation(0, 3, 500);
}

Entity::~Entity()
{
    Debug::log("Entities also dies...", Debug::INFO);
}

void Entity::SetSprite(const char *path)
{
    sprite->LoadSpritesheet(TextureMngr::LoadTexture(path));
}

Sprite *Entity::GetSprite()
{
    return sprite;
}

void Entity::Update()
{
    //std::cout << "X: " << transform->velocity.X << "Y: " << transform->velocity.Y << std::endl;
    transform->Update();
    sprite->destRect.x = (transform->position.X - 16);
    sprite->destRect.y = (transform->position.Y - 64);
    sprite->destRect.h = sprite->srcRect.h * 2;
    sprite->destRect.w = sprite->srcRect.w * 2;

    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active){
            myComponents[i]->Update();
        }
    }
}

void Entity::SetPosition(int x, int y)
{
    xPos = x;
    yPos = y;
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
