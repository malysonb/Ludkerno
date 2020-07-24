#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * @date 23/07/2020
 * Component template to you guys make your owns
 */
#include "Game.hpp"
#include "Debug.hpp"

class Entity;

class Component
{
public:
    bool Active = false;
    void Init();
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual const char* GetName() = 0;
    Entity *Base;
private:
};
