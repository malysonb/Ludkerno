/**
 * @author Malyson Breno de Souza 
 * !Kudos to Lazy's foo!
 * @file CollisionSystem.cpp
 * @version 2.0
 */
#include "../include/CollisionSystem.hpp"
#include "../include/Entity.hpp"
#include "../include/EntityMNGR.hpp"
#include "../include/Components/Collider.hpp"

/*void CollisionSystem::Update()
{
    Obj *iterator = Game::EntityManager.SceneEntities.front();
    while (iterator != nullptr)
    {
        iterator->object->getComponent<Collider>() == nullptr ? 0 : iterator->object->getComponent<Collider>()->isColliding = false;
        Obj *temp = Game::EntityManager.SceneEntities.front();
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
}*/

void CollisionSystem::Update()
{
    for (int x = 0; x < static_cast<int>(Game::EntityManager.SceneEntities.size()); x++)
    {
        Collider *XCol = Game::EntityManager.SceneEntities[x]->object->getComponent<Collider>();
        if (XCol == nullptr)
        {
            continue;
        }
        XCol->isColliding = XCol->isColliding ? false : false;
        for (int y = 0; y < static_cast<int>(Game::EntityManager.SceneEntities.size()); y++)
        {
            Collider *YCol = Game::EntityManager.SceneEntities[y]->object->getComponent<Collider>();
            if (XCol != nullptr && YCol != nullptr)
            {
                if ((XCol->Base->ID != YCol->Base->ID))
                {
                    XCol->isColliding = XCol->isColliding ? true : CheckCollision(XCol, YCol);
                }
            }
        }
    }
}

bool CollisionSystem::CheckCollision(Collider *A, Collider *B)
{
    if (A->L >= B->R)
    {
        return false;
    }
    if (A->R <= B->L)
    {
        return false;
    }
    if (A->T >= B->B)
    {
        return false;
    }
    if (A->B <= B->T)
    {
        return false;
    }
    //std::cout << A->Base->ID << " -> " << B->Base->ID << std::endl;
    return true;
}
