#pragma once

#include "../Screen.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"
#include "Collider.hpp"


class Sand : public Component
{
private:
    /* data */
public:
    Sand(/* args */);
    ~Sand();
    void Init()
    {
        Base->transform->SetScreenPosition(Game::screen.DynamicHPosition(50),
                                           Game::screen.DynamicVPosition(50));
        Base->AddComponent<Collider>(Base);
        Collider *t = Base->getComponent<Collider>();
        t->Init();
        t->L = t->B = t->R = t->T = 1;
    }
    virtual void Update()
    {
        Base->transform->velocity.Y = 1;
    }
    virtual void Render()
    {
        SDL_RenderDrawPoint(Game::renderer, Base->transform->position.X, Base->transform->position.Y);
    }
    virtual const char* GetName()
    {

    }
};
