#pragma once
#include "Ludkerno.hpp"

class Key
{
private:
    
public:
    enum Control
    {
        UP = SDL_SCANCODE_W,
        DOWN = SDL_SCANCODE_S,
        LEFT = SDL_SCANCODE_A,
        RIGHT = SDL_SCANCODE_D,
        ACTION = SDL_SCANCODE_E,
        START = SDL_SCANCODE_RETURN,
        QUIT = SDL_SCANCODE_ESCAPE,
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
        SDL_PumpEvents();
        int windowX, windowY;
        SDL_GetWindowSize(Ludkerno::window, &windowX, &windowY);
        SDL_GetMouseState(&keycode.MouseX, &keycode.MouseY);
        keycode.MouseX = (float)keycode.MouseX / (float)windowX * (float)Ludkerno::WindowSize.X;
        keycode.MouseY = (float)keycode.MouseY / (float)windowY * (float)Ludkerno::WindowSize.Y;
        if (keycode.RIGHT == true)
        {
            keycode.X_Axis = 1;
        }
        else if (keycode.LEFT == true)
        {
            keycode.X_Axis = -1;
        }
        else if (keycode.LEFT == true && keycode.RIGHT == true)
        {
            keycode.X_Axis = 0;
        }
        else
        {
            keycode.X_Axis = 0;
        }

        if (keycode.UP == true)
        {
            keycode.Y_Axis = -1;
        }
        else if (keycode.DOWN == true)
        {
            keycode.Y_Axis = 1;
        }
        else if (keycode.UP == true && keycode.DOWN == true)
        {
            keycode.Y_Axis = 0;
        }
        else
        {
            keycode.Y_Axis = 0;
        }
    }
};