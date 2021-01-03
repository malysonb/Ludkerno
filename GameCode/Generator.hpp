#pragma once
#include "../Ludkerno.hpp"
#include "Cactus.hpp"

class Generator : public Component
{
private:
    Uint32 m_currenttime = 0;
    Uint32 m_lasttime = 0;
    Uint32 WaitTime = 60000;

public:
    void Init()
    {
        m_lasttime = SDL_GetTicks();
        Active = true;
    }
    void Update()
    {
        m_currenttime = SDL_GetTicks();
        if (m_currenttime > m_lasttime + (WaitTime * 1/Game::FrameRate))
        {
            Entity *cactus = Game::EntityManager.Add();
            cactus->transform->SetScreenPosition(Game::screen.DynamicHPosition(101), Game::screen.DynamicVPosition(50));
            cactus->AddComponent<Cactus>(cactus);
            cactus->getComponent<Cactus>()->Init();
            cactus->AddComponent<Collider>(cactus);
            cactus->getComponent<Collider>()->Init();
            int range = Utils::Rand(8,10);
            float res = (range*100)*static_cast<float>(Game::FrameRate);
            WaitTime = static_cast<int>(res);
            m_lasttime = SDL_GetTicks();
            for (int i = 0; i < static_cast<int>(Game::EntityManager.SceneEntities.size()); i++)
            {
                Entity *temp = Game::EntityManager.SceneEntities[i]->object;
                if (temp != nullptr && temp->getComponent<Cactus>() != nullptr)
                {
                    if (temp->transform->GetScreenPosition().X < -16)
                    {
                        Game::EntityManager.Remove(temp->ID);
                    }
                }
            }
        }
    }
    void Render()
    {
    }
    const char *GetName() { return "Generator"; }
};