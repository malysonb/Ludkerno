#include <iostream>
#include <time.h>
#include <string>
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
#include "../include/PkgMngr.hpp"
#include "../include/SceneMngr.hpp"

int Game::FrameRate = 1;

SDL_Renderer *Game::renderer = nullptr;
PkgMngr Game::pkgMngr;
SDL_Event Game::Event;
List Game::EntityManager;
SceneMngr Game::sceneMngr;
Key Game::key;
Camera *Game::camera = nullptr;
Vector2 Game::matrix;
Vector2 Game::camVelocity;
Vector2 Game::WindowSize;
Screen Game::screen;
CollisionSystem collisionSystem;

Scene *ActualScene;

bool notStarted = true;

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
    ActualScene = scene;
    ActualScene->Init();
    notStarted = true;
    Debug::log("Loaded a new scene!", Debug::INFO);
}

void Game::teste(Scene *scene)
{
    LoadScene(scene);
}

void Game::EngineInit(const char *title, int Wx, int Wy)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        Debug::log("Subsystem initialized", Debug::INFO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Wx, Wy, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, 0, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderSetScale(renderer, 2, 2);
        SDL_RenderSetLogicalSize(renderer, 426, 240);
        WindowSize = {426, 240};
        SDL_SetMainReady();
        if (window)
        {
            Debug::log("Window created!", Debug::INFO);
            Running = true;
        }
        else
            Debug::log("Can't to create a window!", Debug::ERROR);
        if (renderer)
        {
            Debug::log("Render initialized", Debug::INFO);
            Running = true;
        }
        else
            Debug::log("Can't to initialize a scene render!", Debug::ERROR);
    }
    else
    {
        Debug::log("Cant initialize SDL!", Debug::ERROR);
        Game::Clear();
    }
    camera = new Camera();
    camera->Init();
    matrix = Vector2::Identity;
    std::cout << "LUDKERNO STARTED! " << VERSION << std::endl;
//Setup();
#ifdef Release
    pkgMngr.Init();
#endif
    LoadScene(sceneMngr.GetScene(0));
    //Loop();
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
    std::string fps = std::to_string(FrameRate);
    SDL_SetWindowTitle(window, fps.c_str());
    if (notStarted)
    {
        Game::EntityManager.Clear();
        ActualScene->Setup();
        notStarted = false;
    }
    matrix = matrix - camera->relativeVelocity;
    camVelocity = camera->relativeVelocity;
    ActualScene->Update();
    camera->Update();
    EntityManager.Update();
    collisionSystem.Update();
    //std::cout << "X: " << Game::matrix.X << " Y: " << Game::matrix.Y << std::endl;
}

void Game::Render()
{
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    if (ActualScene != nullptr)
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

bool Game::IsRunning() { return Running; };