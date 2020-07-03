#include <iostream>
#include "../include/Game.hpp"
#include "../include/Debug.hpp"
#include "../include/Scene.hpp"
#include "../include/Entity.hpp"
#include "../include/Camera.hpp"
#include "../include/EntityMNGR.hpp"
#include "../include/ComponentList.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::Event;
List Game::EntityManager;
Key Game::key;
Camera *Game::camera = nullptr;

Scene* map1;

Game::Game()
{
}
Game::~Game()
{
}
void Game::EngineInit(const char* title, int Wx, int Wy)
{
    //float AspectRatio = (float)Wx/(float)Wy; 
    //std::cout << "AspectRatio: " << AspectRatio << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        Debug::log("Subsystem initialized", Debug::INFO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Wx, Wy, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, 0, 0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //SDL_RenderSetScale(renderer, AspectRatio,AspectRatio);
        SDL_RenderSetLogicalSize(renderer, 400, 300);
        if (window)
        {
            Debug::log("Window created!", Debug::INFO);
            Running = true;
        }
        else Debug::log("Can't to create a window!", Debug::ERROR);
        if (renderer){
            Debug::log("Render initialized", Debug::INFO);
            Running = true;
        }
        else Debug::log("Can't to initialize a scene render!", Debug::ERROR);
    }
    else{
        Debug::log("Cant initialize SDL!", Debug::ERROR);
        Game::Clear();
    }
    camera = new Camera();
    camera->Init();
    Entity *Test = EntityManager.Add("Assets/anim.png",32,32,1);
    Test->SetPosition(0,0);
    Entity *Player = EntityManager.Add("Assets/Array.png",16,32,4);
    Player->SetPosition(200,150);
    Player->AddComponent<Input>();
    Player->getComponent<Input>()->Init(Player);
    map1 = new Scene();
    std::cout << "LUDKERNO STARTED! " << VERSION << std::endl;
}

void Game::HandleEvents()
{
    SDL_PollEvent(&Event);
    switch (Event.type)
    {
    case SDL_QUIT:
        Running = false;
        break;
    default:
        break;
    }
    key.UpdateInputs(Event);
}

void Game::Update()
{
    camera->Update();
    EntityManager.Update();
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    map1->DrawMap();
    EntityManager.Render();
    SDL_RenderPresent(renderer);
}

void Game::Clear()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    Debug::log("Subsystem finalized!", Debug::INFO);
}

bool Game::IsRunning(){ return Running; };