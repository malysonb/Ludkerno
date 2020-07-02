#pragma once
#include "../Game.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"

class Input : public Component
{
public:
    enum Control
    {
        UP = SDLK_w,
        DOWN = SDLK_s,
        LEFT = SDLK_a,
        RIGHT = SDLK_d,
        ACTION = SDLK_e,
        START = SDLK_ESCAPE,
        QUIT = SDLK_F12
    };
    Transform *transform;

    void Init(Entity *Instance)
    {
        Active = true;
        transform = Instance->transform;
        Debug::log("Initializing Input", Debug::INFO);
    }

    void Init(Transform *Instance)
    {
        Active = true;
        transform = Instance;
        Debug::log("Initializing Input", Debug::INFO);
    }

    const char *GetName() { return "Input"; }

    void Update()
    {
        transform->velocity.Y = Game::key.keycode.Y_Axis * 2;
        transform->velocity.X = Game::key.keycode.X_Axis * 2;
    }

    void Render()
    {
        /*Not Implemented*/
    }
};