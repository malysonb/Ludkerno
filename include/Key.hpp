#pragma once
#include "Game.hpp"

class Key
{
public:
    enum Control
    {
        UP = SDL_SCANCODE_W,
        DOWN = SDL_SCANCODE_S,
        LEFT = SDL_SCANCODE_A,
        RIGHT = SDL_SCANCODE_D,
        ACTION = SDL_SCANCODE_E,
        START = SDL_SCANCODE_RETURN,
        QUIT = SDL_SCANCODE_ESCAPE
    };
    struct key_Struct
    {
        float X_Axis = 0;
        float Y_Axis = 0;
        int MouseX = 0;
        int MouseY = 0;
        bool LEFT_CLICK = false;
        bool RIGHT_CLICK = false;
        bool UP = false;
        bool DOWN = false;
        bool LEFT = false;
        bool RIGHT = false;
        bool ACTION = false;
        bool START = false;
        bool QUIT = false;
    };

    key_Struct keycode;
    const Uint8 *pressed = SDL_GetKeyboardState(NULL);

    void UpdateInputs()
    {
        keycode.UP = pressed[UP];
        keycode.LEFT = pressed[LEFT];
        keycode.RIGHT = pressed[RIGHT];
        keycode.DOWN = pressed[DOWN];
        keycode.ACTION = pressed[ACTION];
        keycode.START = pressed[START];
        keycode.QUIT = pressed[QUIT];
        keycode.LEFT_CLICK = static_cast<bool>(SDL_BUTTON(SDL_BUTTON_LEFT));
        keycode.RIGHT_CLICK = static_cast<bool>(SDL_BUTTON(SDL_BUTTON_RIGHT));
        SDL_GetGlobalMouseState(&keycode.MouseX, &keycode.MouseY);
        /*if (event.type == SDL_KEYDOWN)
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
        }*/
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