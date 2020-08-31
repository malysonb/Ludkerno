#pragma once
#include "Game.hpp"
#include "Entity.hpp"

class Obj
{
public:
    Entity *object;
    Obj *NextObj = nullptr;
    Obj(int ID);
    ~Obj();
    Entity* GetEntity();
};

class List
{
    public:
    int Length = 0;
    int IDs = 0;
    Obj *Start = nullptr, *End = nullptr;
    Entity *Add();
    void Remove(int id);
    void Clear();
    void Update();
    void Render();
    Entity *GetByID(int id);
};