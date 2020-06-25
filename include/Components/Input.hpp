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
    Transform* transform;
    void Init(Entity*);
    const char* GetName() {return "Input";}
    void Update();
    void Render();
};