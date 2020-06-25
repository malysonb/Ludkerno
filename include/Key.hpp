#pragma once
#include "Game.hpp"

class Key
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
    struct key_Struct
    {
        float X_Axis = 0;
        float Y_Axis = 0;
        bool UP = false;
        bool DOWN = false;
        bool LEFT = false;
        bool RIGHT = false;
        bool ACTION = false;
        bool START = false;
        bool QUIT = false;
    };

    key_Struct keycode;

    void UpdateInputs(SDL_Event& event)
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case UP:
                keycode.UP = true;
                break;
            case DOWN:
                keycode.DOWN = true;
                break;
            case LEFT:
                keycode.LEFT = true;
                break;
            case RIGHT:
                keycode.RIGHT = true;
                break;
            case START:
                keycode.START = true;
                break;
            case ACTION:
                keycode.ACTION = true;
                break;
            case QUIT:
                keycode.QUIT = true;
                break;
            default:
                break;
            }
        }
        if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
            case UP:
                keycode.UP = false;
                break;
            case DOWN:
                keycode.DOWN = false;
                break;
            case LEFT:
                keycode.LEFT = false;
                break;
            case RIGHT:
                keycode.RIGHT = false;
                break;
            case START:
                keycode.START = false;
                break;
            case ACTION:
                keycode.ACTION = false;
                break;
            case QUIT:
                keycode.QUIT = false;
                break;
            default:
                break;
            }
        }
        if(keycode.RIGHT == true)
        {
            keycode.X_Axis = 1;
        }
        else if(keycode.LEFT == true)
        {
            keycode.X_Axis = -1;
        }
        else if(keycode.LEFT == true && keycode.RIGHT == true)
        {
            keycode.X_Axis = 0;
        }
        else
        {
            keycode.X_Axis = 0;
        }

        if(keycode.UP == true)
        {
            keycode.Y_Axis = -1;
        }
        else if(keycode.DOWN == true)
        {
            keycode.Y_Axis = 1;
        }
        else if(keycode.UP == true && keycode.DOWN == true)
        {
            keycode.Y_Axis = 0;
        }
        else
        {
            keycode.Y_Axis = 0;
        }
    }
};