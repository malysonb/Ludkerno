#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * @date 23/07/2020
 * Component template to you guys make your owns
 */
#include "Ludkerno.hpp"
#include "Debug.hpp"

class Entity;
/**
 * Component template to you guys make your owns
 */
class Component
{
public:
    bool Active = false;
    void Init();
    virtual ~Component()
    {}
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual const char* GetName() = 0;
    virtual void Disable()
    {
        Active = false;
    }
    Entity *Base;
private:
};
