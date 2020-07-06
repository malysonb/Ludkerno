#pragma once
#include "Game.hpp"
#include "Entity.hpp"

class Obj;

struct List
{
    int Length = 0;
    Obj *Start = nullptr, *End = nullptr;
    Entity *Add();
    void Remove(int id);
    void Clear();
    void Update();
    void Render();
    Entity *GetByID(int id);
};