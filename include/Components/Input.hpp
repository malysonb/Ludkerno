#pragma once
#include "../Game.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"
#include "Cactus.hpp"
#include "Collider.hpp"

class Input : public Component
{
public:
    Transform *transform;

    void Init()
    {
        Active = true;
        transform = Base->transform;
        Debug::log("Initializing Input", Debug::INFO);
    }

    const char *GetName() { return "Input"; }
    bool able = true;
    bool onTop = false;
    void Update()
    {
        if(transform->GetScreenPosition().Y >= Game::screen.DynamicVPosition(50))
        {
            able = true;
            onTop = false;
            transform->velocity.Y = 0;
            transform->SetScreenPosition(transform->GetScreenPosition().X ,Game::screen.DynamicVPosition(50));
        }
        if(transform->GetScreenPosition().Y < Game::screen.DynamicVPosition(50) && able == false && onTop)
        {
            transform->velocity.Y = 5;
        }
        if(transform->GetScreenPosition().Y <= Game::screen.DynamicVPosition(30))
        {
            onTop = true;
        }
        if(Game::key.keycode.UP && able == true)
        {
            if(onTop == false)
            {
                transform->velocity.Y = -5;
                able = false;
            }   
        }
        if(Base->getComponent<Collider>()->isColliding)
        {
            std::cout << "AAAAAAAAAAAAA" << std::endl;
        }
        /*transform->velocity.Y = Game::key.keycode.Y_Axis * 2;
        transform->velocity.X = Game::key.keycode.X_Axis * 2;
        if(transform->position.X >= Game::camera->middle.X)
        {
            Game::camera->Move(Vector2::AX, transform->velocity.X);
        }
        if(transform->position.Y >= Game::camera->middle.Y)
        {
            Game::camera->Move(Vector2::AY, transform->velocity.Y);
        }*/
    }

    void Render()
    {
        /*Not Implemented*/
    }
};