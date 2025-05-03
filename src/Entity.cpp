#include "../include/Ludkerno.hpp"
#include "../include/Entity.hpp"
#include "../include/Components/Collider.hpp"
#include "../include/RenderPipeline.hpp"
#include "../include/Camera.hpp"
#include "../include/Object2D.hpp"
#include "../include/Key.hpp" // Ensure the definition of Key is included

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
    m_Origin = nullptr;
    for (int i = 0; i < m_MaxComponents; i++)
    {
        myComponents[i] = nullptr;
    }
    RenderPipeline::GetInstance()->add2Pipeline(this);
}

Entity::~Entity()
{
    delete transform;
    for(int i = 0; i < m_NumComponents; i++)
    {
        if(myComponents[i])
            delete myComponents[i];
    }
    RenderPipeline::GetInstance()->remove(this);
}

void Entity::SetSprite(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations)
{
    AddComponent<Sprite>(this);
    m_mySprite = getComponent<Sprite>();
    m_mySprite->Base = this;
    m_mySprite->Init(texturePath, Size_x, Size_y, n_ofAnimations);
    m_mySprite->SetupAnimation(0, 0, 500);
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
    //transform->position = transform->position - Ludkerno::camVelocity;
    transform->Update();
    //printf("%f\n", transform->velocity.Y);
    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active)
        {
            myComponents[i]->Update();
        }
    }
    if (m_mySprite != nullptr)
    {
        m_mySprite->destRect.x = static_cast<int>(transform->GetScreenPosition().X) - static_cast<int>(m_mySprite->OriginPoint.X * transform->scale.X);
        m_mySprite->destRect.y = static_cast<int>(transform->GetScreenPosition().Y) - static_cast<int>(m_mySprite->OriginPoint.Y * transform->scale.Y);
        m_mySprite->destRect.h = m_mySprite->srcRect.h * static_cast<int>(transform->scale.Y);
        m_mySprite->destRect.w = m_mySprite->srcRect.w * static_cast<int>(transform->scale.X);
    }
    if(debug)
    {
        debugEntity();
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
    if (getComponent<Collider>() != nullptr && getComponent<Collider>()->isColliding && debug)
    {
        SDL_SetRenderDrawColor(Ludkerno::renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(Ludkerno::renderer, &m_mySprite->destRect);
    }
}

Vector2 Entity::GetSpriteSize(){
    if (m_mySprite != nullptr)
    {
        return Vector2(m_mySprite->srcRect.w * transform->scale.X, m_mySprite->srcRect.h * transform->scale.Y);
    }
    else
    {
        return Vector2(0, 0);
    }
}

void Entity::debugEntity(){
    std::system("clear");
    std::cout << "Posição na tela: " << transform->GetScreenPosition().X << " " << transform->GetScreenPosition().Y << std::endl;
    std::cout << "Posição Global: " << transform->position.X << " " << transform->position.Y << std::endl;
    std::cout << "Velocidade: " << transform->velocity.X << " " << transform->velocity.Y << std::endl;
    std::cout << "Camera:" << Ludkerno::camera->GetCameraPos().X << " " << Ludkerno::camera->GetCameraPos().Y << std::endl;
    std::cout << "Matrix: " << Ludkerno::matrix.X << " " << Ludkerno::matrix.Y << std::endl;
    std::cout << "Sprite size: " << m_mySprite->srcRect.w * transform->scale.X << " " << m_mySprite->srcRect.h * transform->scale.Y << std::endl;
    std::cout << "Mouse na tela: " << Ludkerno::key.keycode.MouseX << " " << Ludkerno::key.keycode.MouseY << std::endl;
    std::cout << "Mouse Global: " << Ludkerno::key.keycode.MouseX - Ludkerno::matrix.X << " " << Ludkerno::key.keycode.MouseY - Ludkerno::matrix.Y << std::endl;
    if (getComponent<Collider>() != nullptr && getComponent<Collider>()->isColliding)
    {
        std::cout << "colDirection: " << getComponent<Collider>()->colDirection.X << " " << getComponent<Collider>()->colDirection.Y << std::endl;
    }
    for (int i = 0; i < m_NumComponents; i++)
    {
        if (myComponents[i]->Active)
            std::cout << myComponents[i]->GetName() << std::endl;
    }
}

std::string Entity::toString() {
    uintptr_t pointer = reinterpret_cast<uintptr_t>(this);
    std::stringstream name;
    name << typeid(*this).name() << "@" << "0x" << std::hex << pointer;
    return name.str();
}