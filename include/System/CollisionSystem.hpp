#pragma once
#include "Ludkerno.hpp"
#include "TileLayer.hpp"
#include "Entity.hpp" // Include the header file where Entity is defined

class Collider;

struct CollisionSystem
{
    private:
    public:
    int Length = 0;
    void Update();
    bool CheckCollision(Collider* A, Collider* B);
    Vector2 CollisionDirection(Collider *A, Collider *B);
    void UpdateWithTiles(TileLayer *tileLayer);
    void CheckCollisionWithTiles(Entity *entity, TileLayer *tileLayer);
};