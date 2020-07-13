#pragma once
#include "Game.hpp"
#include "Entity.hpp"
#include "Components/Collider.hpp"

class Obj;

struct CollisionSystem
{
    private:
    public:
    int Length = 0;
    Obj *Start = nullptr, *End = nullptr;
    Collider *Add();
    void Remove(int id);
    void Clear();
    void Update();
    Collider *GetByID(int id);
};