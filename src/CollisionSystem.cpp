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
#include "../include/TileLayer.hpp"
#include "../include/Object.hpp"

void CollisionSystem::Update()
{
    auto &entities = EntityMngr::GetInstance()->SceneEntities;

    for (size_t x = 0; x < entities.size(); x++)
    {
        Collider *XCol = entities[x]->object->getComponent<Collider>();
        if (XCol == nullptr)
        {
            continue;
        }

        // Resetando o estado de colisão
        XCol->isColliding = false;

        for (size_t y = x + 1; y < entities.size(); y++) // Evita verificações duplicadas
        {
            Collider *YCol = entities[y]->object->getComponent<Collider>();
            if (YCol == nullptr)
            {
                continue;
            }

            // Verifica colisão
            if (CheckCollision(XCol, YCol))
            {
                XCol->isColliding = true;
                YCol->isColliding = true; // Atualiza ambos os lados da colisão

                // Calcula a direção da colisão
                Vector2 collisionDir = CollisionDirection(XCol, YCol);

                // Ajuste de posição apenas se necessário
                if (collisionDir.X != 0 || collisionDir.Y != 0)
                {
                    entities[x]->object->transform->position.X -= collisionDir.X / 2;
                    entities[x]->object->transform->position.Y -= collisionDir.Y / 2;

                    entities[y]->object->transform->position.X += collisionDir.X / 2;
                    entities[y]->object->transform->position.Y += collisionDir.Y / 2;
                }
            }
        }
    }
}

void CollisionSystem::UpdateWithTiles(TileLayer *tileLayer)
{
    auto &entities = EntityMngr::GetInstance()->SceneEntities;

    for (size_t x = 0; x < entities.size(); x++)
    {
        Collider *XCol = entities[x]->object->getComponent<Collider>();
        if (XCol == nullptr)
        {
            continue;
        }

        // Resetando o estado de colisão
        XCol->isColliding = false;

        // Verifica colisão com outros objetos
        for (size_t y = x + 1; y < entities.size(); y++)
        {
            Collider *YCol = entities[y]->object->getComponent<Collider>();
            if (YCol == nullptr)
            {
                continue;
            }

            if (CheckCollision(XCol, YCol))
            {
                XCol->isColliding = true;
                YCol->isColliding = true;

                Vector2 collisionDir = CollisionDirection(XCol, YCol);

                // Ajuste de posição apenas se necessário
                if (collisionDir.X != 0 || collisionDir.Y != 0)
                {
                    entities[x]->object->transform->position.X -= collisionDir.X / 2;
                    entities[x]->object->transform->position.Y -= collisionDir.Y / 2;

                    entities[y]->object->transform->position.X += collisionDir.X / 2;
                    entities[y]->object->transform->position.Y += collisionDir.Y / 2;
                }
            }
        }

        // Verifica colisão com tiles
        if(tileLayer != nullptr)
            CheckCollisionWithTiles(entities[x]->object, tileLayer);
    }
}
/**
 * @brief Verifica a colisão entre uma entidade e os tiles de um TileLayer.
 * 
 * @param entity A entidade a ser verificada.
 * @param tileLayer O TileLayer com o qual a entidade deve colidir.
 */
void CollisionSystem::CheckCollisionWithTiles(Entity *entity, TileLayer *tileLayer)
{
    Collider *collider = entity->getComponent<Collider>();
    if (collider == nullptr)
    {
        return;
    }

    Vector2 entityPos = entity->transform->position;
    Vector2 entitySize = entity->GetSpriteSize();
    collider->colDirection = Vector2::Zero;

    for (int row = 0; row < tileLayer->rows; row++)
    {
        for (int col = 0; col < tileLayer->cols; col++)
        {
            int tileID = tileLayer->map[row][col];
            if (tileID == 4) // Tile vazio, sem colisão
            {
                continue;
            }

            // Calcular os limites do tile
            float tileLeft = col * 16;
            float tileRight = tileLeft + 16;
            float tileTop = row * 16;
            float tileBottom = tileTop + 16;

            // Calcular os limites do objeto
            float objLeft = entityPos.X - entity->GetSprite()->OriginPoint.X;
            float objRight = objLeft + entitySize.X;
            float objBottom = entityPos.Y;
            float objTop = objBottom - entitySize.Y;

            // Verificar colisão com o tile
            if (objRight > tileLeft && objLeft < tileRight && objBottom > tileTop && objTop < tileBottom)
            {
                collider->isColliding = true;

                // Ajustar a posição do objeto para evitar sobreposição
                int overlapX = std::min(objRight, tileRight) - std::max(objLeft, tileLeft);
                int overlapY = std::min(objBottom, tileBottom) - std::max(objTop, tileTop);

                if (overlapX < overlapY)
                {
                    // Ajusta a posição horizontalmente
                    if (objLeft < tileLeft)
                    {
                        entity->transform->SetPosition(entity->transform->GetPosition().X - overlapX, entity->transform->GetPosition().Y);
                        collider->colDirection = collider->colDirection + Vector2(-1, 0);
                    }
                    else
                    {
                        entity->transform->SetPosition(entity->transform->GetPosition().X + overlapX, entity->transform->GetPosition().Y);
                        collider->colDirection = collider->colDirection + Vector2(1, 0);
                    }
                }
                else
                {
                    // Ajusta a posição verticalmente
                    if (objTop < tileTop)
                    {
                        entity->transform->SetPosition(entity->transform->GetPosition().X, entity->transform->GetPosition().Y - overlapY);
                        collider->colDirection = collider->colDirection + Vector2(0, -1);
                    }
                    else
                    {
                        entity->transform->SetPosition(entity->transform->GetPosition().X, entity->transform->GetPosition().Y + overlapY);
                        collider->colDirection = collider->colDirection + Vector2(0, 1);
                    }
                }
            }
        }
    }
    collider->colDirection = Vector2::Direction(&collider->colDirection);
}

bool CollisionSystem::CheckCollision(Collider *A, Collider *B)
{
    // Verifica se os retângulos se sobrepõem
    return !(A->L >= B->R || A->R <= B->L || A->T >= B->B || A->B <= B->T);
}

Vector2 CollisionSystem::CollisionDirection(Collider *A, Collider *B)
{
    // Calcula a direção da colisão
    float overlapX = std::min(A->R, B->R) - std::max(A->L, B->L);
    float overlapY = std::min(A->B, B->B) - std::max(A->T, B->T);

    if (overlapX < overlapY)
    {
        return Vector2(overlapX, 0);
    }
    else
    {
        return Vector2(0, overlapY);
    }
}
