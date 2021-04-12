#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * @date 23/07/2020
 * A simple entity code with ECS.
 */
#include "Game.hpp"
#include "Components/Sprite.hpp"
#include "Transform.hpp"

class Entity
{
public:
    Entity();
    ~Entity();

    void Update();
    void Render();

    void SetSprite(const char *TexturePath, int s_x, int s_y, int n_ofAnimations);
    void SetSprite(Sprite sprite);
    void SetPosition(float x, float y);

    template <typename newComp>
    void AddComponent(Entity *Owner = nullptr)
    {
        if (std::is_base_of<Component, newComp>::value)
        {
            if (m_NumComponents < m_MaxComponents)
            {
                Component *temp = new newComp();
                temp->Base = Owner;
                myComponents[m_NumComponents] = temp;
                //Debug::log("Added a new component!", Debug::INFO);
                m_NumComponents++;
            }
            else
            {
                Debug::log("You reached the max components in this entity!", Debug::WARN);
                Debug::log("You can't to add more components!", Debug::ERROR);
            }
        }
        else
        {
            Debug::log("This is not a component!", Debug::ERROR);
        }
    }

    template <typename comp>
    comp *getComponent()
    {
        for (int i = 0; i < m_NumComponents; i++)
        {
            if (dynamic_cast<comp *>(myComponents[i]))
            {
                return (comp *)myComponents[i];
            }
        }
        //Debug::log("Can't find component!", Debug::ERROR);
        return nullptr;
    }
    Sprite *GetSprite();

    Transform *transform = nullptr;
    int ID;

private:
    Sprite *m_mySprite;
    static const int m_MaxComponents = 10;
    Component *myComponents[m_MaxComponents];
    int m_NumComponents = 0;
    int xPos = 0;
    int yPos = 0;
    SDL_Point *m_Origin;
};
