#pragma once

#include "Game.hpp"
#include "Components/Transform.hpp"

class Camera
{
private:
public:
    Transform transform;
    Transform *follow;
    Vector2 startMatrix;
    Vector2 middle;

    void Init()
    {
        middle.X = 200;
        middle.Y = 150;
        startMatrix = Vector2::Identity;
    }
    void Update()
    {
        if (transform.position.X + follow->velocity.X >= Game::matrix.X)
        {
            if (follow->position.X >= middle.X)
                transform.velocity.X = follow->velocity.X;
        }
        else if(Game::matrix.X > 0)
        {
            transform.velocity.X = 1;
        }
        else
        {
            transform.velocity.X = 0;
        }
        if (transform.position.Y + follow->velocity.Y >= Game::matrix.Y)
        {
            if (follow->position.Y >= middle.Y)
                transform.velocity.Y = follow->velocity.Y;
        }
        else if(Game::matrix.Y > 0)
        {
            transform.velocity.Y = 1;
        }
        else
        {
            transform.velocity.Y = 0;
        }
        transform.Update();
    }
    void FollowPoint(Transform *who)
    {
        follow = who;
    }
};