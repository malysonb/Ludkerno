#include <iostream>
#include <time.h>
#include <chrono>
#include "../include/Game.hpp"
#include "../include/Debug.hpp"
#include "../include/Scene.hpp"
#include "../include/Entity.hpp"
#include "../include/Camera.hpp"
#include "../include/EntityMNGR.hpp"
#include "../include/ComponentList.hpp"
#include "../include/Screen.hpp"
#include "../include/CollisionSystem.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::Event;
List Game::EntityManager;
Key Game::key;
Camera *Game::camera = nullptr;
Vector2 Game::matrix;
Vector2 Game::camVelocity;
Vector2 Game::WindowSize;
Screen Game::screen;
CollisionSystem collisionSystem;

Scene* ActualScene;

Game::Game()
{
}
Game::~Game()
{
}

int Game::Rand(int min, int max)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    return rand() % (max - min) + min;
}

void Game::Setup()
{
    
}

void Game::LoadScene(Scene *scene)
{
    EntityManager.Clear();
    ActualScene = scene;
    ActualScene->Init();
    ActualScene->Setup();
    Debug::log("Loaded a new scene!",Debug::INFO);
}

void Game::EngineInit(const char* title, int Wx, int Wy)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        Debug::log("Subsystem initialized", Debug::INFO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Wx, Wy, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, 0, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderSetScale(renderer, 2, 2);
        SDL_RenderSetLogicalSize(renderer, Wx/2, Wy/2);
        WindowSize = {Wx/2, Wy/2};
        SDL_SetMainReady();
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
    matrix = Vector2::Identity;
    std::cout << "LUDKERNO STARTED! " << VERSION << std::endl;
    //Setup();
}

void Game::HandleEvents()
{
    SDL_PollEvent(&Event);
    key.UpdateInputs(Event);
    switch (Event.type)
    {
    case SDL_QUIT:
        Running = false;
        break;
    default:
        break;
    }
}

void Game::Update()
{
    matrix = matrix - camera->relativeVelocity;
    camVelocity = camera->relativeVelocity;
    camera->Update();
    EntityManager.Update();
    collisionSystem.Update();
    //std::cout << "X: " << Game::matrix.X << " Y: " << Game::matrix.Y << std::endl;
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    if(ActualScene != nullptr)
        ActualScene->DrawMap();
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