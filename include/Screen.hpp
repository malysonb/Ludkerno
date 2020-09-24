#pragma once
#include "Game.hpp"

class Screen
{
private:
public:
    Vector2 GetWindowSize()
    {
        return Game::WindowSize;
    }

    /**
     * Type the percentage and it will return the Horizontal position in your screen.
     * 
     * @param Percentage is the position you want in your screen
     * @return Position in pixel in the screen.
    **/
    int DynamicHPosition(float Percentage)
    {
        return static_cast<int>((Percentage * Game::WindowSize.X) / 100.0f);
    }

    /**
     * Type the percentage and it will return the Vertical position in your screen.
     * 
     * @param Percentage is the position you want in your screen
     * @return Position in pixel in the screen.
    **/
    int DynamicVPosition(float Percentage)
    {
        return static_cast<int>((Percentage * Game::WindowSize.Y) / 100.0f);
    }
};