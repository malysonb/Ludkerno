#pragma once

#include "Game.hpp"
#include "Sand.hpp"
#include "Screen.hpp"

class SandSimEnv
{
private:
    /* data */
public:
    Sand **env;
    Vector2 windowSize = Game::screen.GetWindowSize();
    SandSimEnv()
    {
        env = new Sand*[windowSize.X];
    }
    ~SandSimEnv();
};
