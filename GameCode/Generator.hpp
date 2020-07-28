#pragma once
#include "../Ludkerno.hpp"
#include "Cactus.hpp"

class Generator : public Component
{
private:
    Uint32 m_currenttime = 0;
    Uint32 m_lasttime = 0;
    Uint32 WaitTime = 100;

public:
    void Init()
    {
        m_lasttime = SDL_GetTicks();
        Active = true;
    }
    void Update()
    {
        m_currenttime = SDL_GetTicks();
        if (m_currenttime > m_lasttime + (WaitTime * 1000/Game::FrameRate))
        {
            Entity *cactus = Game::EntityManager.Add();
            cactus->transform->SetScreenPosition(Game::screen.DynamicHPosition(101), Game::screen.DynamicVPosition(50));
            cactus->AddComponent<Cactus>(cactus);
            cactus->getComponent<Cactus>()->Init();
            cactus->AddComponent<Collider>(cactus);
            cactus->getComponent<Collider>()->Init();
            WaitTime = Game::Rand(40, 90);
            m_lasttime = SDL_GetTicks();
            for (int i = 0; i < Game::EntityManager.Length; i++)
            {
                Entity *temp = Game::EntityManager.GetByID(i);
                if (temp->getComponent<Cactus>() != nullptr)
                {
                    if (temp->transform->GetScreenPosition().X < -16)
                    {
                        Game::EntityManager.Remove(i);
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