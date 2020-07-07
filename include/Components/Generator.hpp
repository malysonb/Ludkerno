#pragma once
#include "../Game.hpp"
#include "../Screen.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"
#include "../EntityMNGR.hpp"
#include "Cactus.hpp"

class Generator : public Component
{
private:
    Uint32 m_currenttime = 0;
    Uint32 m_lasttime = 0;
    Uint32 WaitTime = 1000;

public:
    void Init()
    {
        Active = true;
    }
    void Update()
    {
        m_currenttime = SDL_GetTicks();
        if (m_currenttime > m_lasttime + WaitTime)
        {
            Entity *cactus = Game::EntityManager.Add();
            cactus->transform->SetScreenPosition(Game::screen.DynamicHPosition(101), Game::screen.DynamicVPosition(50));
            cactus->AddComponent<Cactus>(cactus);
            cactus->getComponent<Cactus>()->Init();
            cactus->Update();
            cactus->Render();
            WaitTime = Game::Rand(500, 2000);
            std::cout << WaitTime << std::endl;
            m_lasttime = SDL_GetTicks();
            for (int i = 0; i < Game::EntityManager.Length; i++)
            {
                Entity *temp = Game::EntityManager.GetByID(i);
                if (temp->getComponent<Cactus>() != nullptr)
                {
                    if (temp->transform->GetScreenPosition().X < -32)
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