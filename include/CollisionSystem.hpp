#pragma once
#include "Ludkerno.hpp"

class Collider;

struct CollisionSystem
{
    private:
    public:
    int Length = 0;
    void Update();
    bool CheckCollision(Collider* A, Collider* B);
};