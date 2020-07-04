#pragma once
#include "Game.hpp"
#include "Entity.hpp"

class Obj
{
public:
    Entity *object;
    Obj *NextObj = nullptr;
    Obj(int ID)
    {
        object = new Entity();
        object->ID = ID;
    }
    ~Obj()
    {
        delete object;
    }
};

struct List
{
    int Length = 0;
    Obj *Start = nullptr, *End = nullptr;
    Entity *Add();
    void Remove(int id);
    void Clear();
    void Update();
    void Render();
};