/**
 * @author Malyson Breno de Souza 
 * !Kudos to Lazy's foo!
 * @file CollisionSystem.cpp
 * @version 1.0
 */
#include "../include/CollisionSystem.hpp"
#include "../include/Entity.hpp"
#include "../include/EntityMNGR.hpp"
#include "../include/Components/Collider.hpp"

void CollisionSystem::Update()
{
    Obj *iterator = Game::EntityManager.Start;
    while (iterator != nullptr)
    {
        iterator->object->getComponent<Collider>() == nullptr ? : iterator->object->getComponent<Collider>()->isColliding = false;
        Obj *temp = Game::EntityManager.Start;
        while (temp != nullptr)
        {
            Entity *A = iterator->object, *B = temp->object;
            if (A->ID != B->ID)
            {
                Collider *Aa = A->getComponent<Collider>(),
                         *Bb = B->getComponent<Collider>();
                if(Aa != nullptr && Bb != nullptr)
                {
                    Aa->isColliding = Aa->isColliding == true ? true : CheckCollision(Aa, Bb);
                }
            }
            temp = temp->NextObj;
        }
        iterator = iterator->NextObj;
    }
}
bool CollisionSystem::CheckCollision(Collider* A, Collider* B)
{
    if(A->L >= B->R)
    {
        return false;
    }
    if(A->R <= B->L)
    {
        return false;
    }
    if(A->T >= B->B)
    {
        return false;
    }
    if(A->B <= B->T)
    {
        return false;
    }
    std::cout << A->Base->ID << " -> " << B->Base->ID << std::endl;
    return true;
}
