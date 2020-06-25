#pragma once
#include "Game.hpp"
#include "Components/Sprite.hpp"
#include "Components/Transform.hpp"

class Entity
{
public:
    Entity(const char *TexturePath, int s_x, int s_y, int n_ofAnimations);
    ~Entity();

    void Update();
    void Render();

    void SetSprite(const char *);
    void SetPosition(int x, int y);

    template <typename newComp>
    void AddComponent()
    {
        if (m_NumComponents < m_MaxComponents)
        {
            myComponents[m_NumComponents] = new newComp();
            Debug::log("Added a new component!", Debug::INFO);
            m_NumComponents++;
            std::cout << "Theres is " << m_NumComponents << std::endl;
        }
        else
        {
            Debug::log("You reached the max components in this entity!", Debug::WARN);
            Debug::log("You can't to add more components!", Debug::ERROR);
        }
    }
    
    template <typename comp>
    comp *getComponent()
    {
        for (int i = 0; i < m_NumComponents; i++)
        {
            if (dynamic_cast<comp *>(myComponents[i]))
            {
                Debug::log("Found Component!", Debug::INFO);
                return (comp *)myComponents[i];
            }
        }
        Debug::log("Can't find component!", Debug::ERROR);
        return nullptr;
    }
    Sprite *GetSprite();

    Transform *transform;
    int ID;

private:
    static const int m_MaxComponents = 10;
    Component *myComponents[m_MaxComponents];
    int m_NumComponents = 0;
    int xPos = 0;
    int yPos = 0;
    SDL_Point *m_Origin;
};
