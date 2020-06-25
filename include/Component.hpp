#pragma once
#include "Game.hpp"
#include "Debug.hpp"

class Component
{
public:
    bool Active = false;
    void Init();
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual const char* GetName() = 0;
private:
};
