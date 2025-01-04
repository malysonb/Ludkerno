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

void CollisionSystem::Update()
{
    for (int x = 0; x < static_cast<int>(EntityMngr::GetInstance()->SceneEntities.size()); x++)
    {
        Collider *XCol = EntityMngr::GetInstance()->SceneEntities[x]->object->getComponent<Collider>();
        if (XCol == nullptr)
        {
            continue;
        }
        XCol->isColliding = XCol->isColliding ? false : false;
        for (int y = 0; y < static_cast<int>(EntityMngr::GetInstance()->SceneEntities.size()); y++)
        {
            Collider *YCol = EntityMngr::GetInstance()->SceneEntities[y]->object->getComponent<Collider>();
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
