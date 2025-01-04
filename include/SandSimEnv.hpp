#pragma once

#include "Ludkerno.hpp"
#include "Vector2.hpp"
#include "Sand.hpp"
#include "Screen.hpp"

class SandSimEnv
{
private:
    /* data */
public:
    Sand **env;
    Vector2 windowSize = Ludkerno::screen.GetWindowSize();
    SandSimEnv()
    {
        env = new Sand*[windowSize.X];
    }
    ~SandSimEnv();
};
