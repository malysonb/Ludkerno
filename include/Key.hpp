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
        LEFT_CLICK = SDL_BUTTON_LEFT,
        RIGHT_CLICK = SDL_BUTTON_RIGHT,
        MIDDLE_CLICK = SDL_BUTTON_MIDDLE,
    };
    struct key_Struct
    {
        float X_Axis = 0;
        float Y_Axis = 0;
        int MouseX = 0;
        int MouseY = 0;
        bool LEFT_CLICK = false;
        bool RIGHT_CLICK = false;
        bool MIDDLE_CLICK = false;
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
        keycode.MouseX = static_cast<float>(keycode.MouseX) / windowX * Ludkerno::WindowSize.X;
        keycode.MouseY = static_cast<float>(keycode.MouseY) / windowY * Ludkerno::WindowSize.Y;
        Uint32 mouseState = SDL_GetMouseState(NULL, NULL);
        keycode.LEFT_CLICK = mouseState & SDL_BUTTON(SDL_BUTTON_LEFT);
        keycode.RIGHT_CLICK = mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT);
        keycode.MIDDLE_CLICK = mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE);

        keycode.X_Axis = (keycode.RIGHT ? 1 : 0) - (keycode.LEFT ? 1 : 0);
        keycode.Y_Axis = (keycode.DOWN ? 1 : 0) - (keycode.UP ? 1 : 0);
    }
};