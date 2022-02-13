#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include "../include/Ludkerno.hpp"
#include "../include/Debug.hpp"
#include "../include/Scene.hpp"
#include "../include/Entity.hpp"
#include "../include/Camera.hpp"
#include "../include/Key.hpp"
#include "../include/EntityMNGR.hpp"
#include "../include/ComponentList.hpp"
#include "../include/Screen.hpp"
#include "../include/CollisionSystem.hpp"
#include "../include/SceneMngr.hpp"
#include "../include/RenderPipeline.hpp"

const int FPS = 60;
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime = SDL_GetTicks();

float Ludkerno::FrameRate = 1;
float Ludkerno::DeltaTime = 1;

Ludkerno *Ludkerno::instance_ = nullptr;
bool Ludkerno::Running_ = false;

SDL_Window *Ludkerno::window = nullptr;
SDL_Renderer *Ludkerno::renderer = nullptr;
SDL_Event Ludkerno::Event;
Key Ludkerno::key;
Camera *Ludkerno::camera = nullptr;
Vector2 Ludkerno::matrix;
Vector2 Ludkerno::camVelocity;
Vector2 Ludkerno::WindowSize;
Screen Ludkerno::screen;
CollisionSystem collisionSystem;

Scene *ActualScene;

bool notStarted = true;


Ludkerno::Ludkerno()
{
}

Ludkerno *Ludkerno::GetInstance()
{
    if (instance_ == nullptr)
    {
        Debug::log("Ludkerno is not instantiated.", Debug::ERROR);
        Running_ = false;
        return nullptr;
    }
    return instance_;
}

Scene *Ludkerno::GetScene()
{
    return ActualScene;
}

void Ludkerno::LoadScene(Scene *scene)
{
    if (scene == NULL)
    {
        Debug::log("Scene not found!", Debug::ERROR);
    }
    ActualScene = scene;
    notStarted = true;
    Debug::log("Loaded a new scene!", Debug::INFO);
}

void Ludkerno::EngineInit(const char *title, int Wx, int Wy, int Lx, int Ly)
{
    if (instance_ == nullptr)
    {
        instance_ = new Ludkerno();
    }
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) == 0)
    {
        Debug::log("Subsystem initialized", Debug::INFO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Wx, Wy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderSetScale(renderer, 2, 2);
        SDL_RenderSetLogicalSize(renderer, Lx, Ly);
        WindowSize = {426, 240};
        //SDL_SetMainReady();
        if (window)
        {
            Debug::log("Window created!", Debug::INFO);
            Running_ = true;
        }
        else
            Debug::log("Can't to create a window!", Debug::ERROR);
        if (renderer)
        {
            Debug::log("Render initialized", Debug::INFO);
            Running_ = true;
        }
        else
            Debug::log("Can't to initialize a scene render!", Debug::ERROR);
    }
    else
    {
        Debug::log(SDL_GetError(), Debug::ERROR);
        Ludkerno::Clear();
    }
    frameTime = SDL_GetTicks();
    camera = new Camera();
    camera->Init();
    matrix = Vector2::Identity;
    std::string motd = "LUDKERNO RUNTIME ";
    motd += VERSION;
    Debug::log(motd, Debug::INFO);
#ifdef Release

#endif
    LoadScene(SceneMngr::GetInstance()->GetScene(0));
    //Loop();
}

void Ludkerno::HandleEvents()
{
    SDL_PollEvent(&Event);
    key.UpdateInputs();
    switch (Event.type)
    {
    case SDL_QUIT:
        Running_ = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        switch (Event.button.button)
        {
        case SDL_BUTTON_LEFT:
            key.keycode.LEFT_CLICK = true;
            break;
        case SDL_BUTTON_RIGHT:
            key.keycode.RIGHT_CLICK = true;
            break;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        switch (Event.button.button)
        {
        case SDL_BUTTON_LEFT:
            key.keycode.LEFT_CLICK = false;
            break;
        case SDL_BUTTON_RIGHT:
            key.keycode.RIGHT_CLICK = false;
            break;
        }
        break;
    default:
        break;
    }
}

void Ludkerno::Update()
{
    DeltaTime = 30 / FrameRate <= 1 ? 1 : 30 / FrameRate;
    if (ActualScene == nullptr)
    {
        Debug::log("No scene loaded!", Debug::Level::ERROR);
        Running_ = false;
        return;
    }
    if (notStarted)
    {
        EntityMngr::GetInstance()->Clear();
        RenderPipeline::GetInstance()->Clear();
        ActualScene->Setup();
        notStarted = false;
    }
    matrix = matrix - camera->relativeVelocity;
    ActualScene->Update();
    camera->Update();
    camVelocity = camera->relativeVelocity;
    EntityMngr::GetInstance()->Update();
    collisionSystem.Update();
}

void Ludkerno::Render()
{
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    /*if (ActualScene != nullptr)
        ActualScene->DrawMap();
    EntityManager.Render();*/
    RenderPipeline::GetInstance()->Render();
    SDL_RenderPresent(renderer);
}

void Ludkerno::Clear()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    Debug::log("Subsystem finalized!", Debug::INFO);
}

bool Ludkerno::IsRunning() { return Running_; }

Uint32 Ludkerno::GetCurrentTicks()
{
    return SDL_GetTicks();
}

void Ludkerno::Loop()
{
    try
    {
        while (Ludkerno::Running_)
        {
            frameStart = SDL_GetTicks();
            instance_->HandleEvents();
            instance_->Update();
            instance_->Render();
            frameTime = SDL_GetTicks() - frameStart;
            Ludkerno::FrameRate = frameTime != 0 ? 1000 / (frameDelay + frameTime) : Ludkerno::FrameRate;
            Ludkerno::FrameRate == 0 ? Ludkerno::FrameRate++ : Ludkerno::FrameRate;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Ludkerno::StopLudkerno(){
    Running_ = false;
}