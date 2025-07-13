#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include "Ludkerno.hpp"
#include "System/Debug.hpp"
#include "Scene.hpp"
#include "Entity.hpp"
#include "Camera.hpp"
#include "Key.hpp"
#include "System/EntityMNGR.hpp"
#include "ComponentList.hpp"
#include "Screen.hpp"
#include "System/CollisionSystem.hpp"
#include "System/SceneMngr.hpp"
#include "System/RenderPipeline.hpp"

//target FPS
const int FPS = 60;
int frameDelay = 1000 / FPS;
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
Vector2 Ludkerno::matrix; // Representa o ponto zero do mundo.
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
    if(SceneMngr::GetInstance()->sceneVector.size() == 0)
    {
        Debug::log("No Scene was Loaded!", Debug::ERROR);
        Running_ = false;
        return;
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
        WindowSize = {(float)Lx, (float)Ly};
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
    default:
        break;
    }
}

void Ludkerno::Update()
{
    DeltaTime = 60 / FrameRate <= 1 ? 1 : 60 / FrameRate;
    //std::string title = "Ludkerno - FPS: " + std::to_string(static_cast<int>(FrameRate)) + " - DeltaTime: " + std::to_string(DeltaTime);
    //Debug::log(title, Debug::INFO);
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
    if(ActualScene->GetLayerCount() > 0)
    {
        collisionSystem.UpdateWithTiles(ActualScene->layers[0]);
    }else{
        collisionSystem.UpdateWithTiles(nullptr);
    }
    ActualScene->Update();
    camera->Update();
    matrix = -camera->GetCameraPos(); // Ajustar a matriz para o deslocamento correto
    EntityMngr::GetInstance()->Update();
    //collisionSystem.Update();
}

void Ludkerno::Render()
{
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
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
            frameDelay = (1000 / FPS) - frameTime;
            if (frameDelay > 0) {
                SDL_Delay(frameDelay);
            }
            if (frameTime + frameDelay > 0) {
                Ludkerno::FrameRate = 1000.0f / (frameTime + frameDelay);
            } else {
                Ludkerno::FrameRate = 0; // Ou algum valor padrão
            }
            Ludkerno::FrameRate == 0 ? Ludkerno::FrameRate++ : Ludkerno::FrameRate;
            //std::string fpsMessage = "FPS: " + std::to_string(static_cast<int>(Ludkerno::FrameRate));
            //Debug::log(fpsMessage, Debug::INFO);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        Debug::log("An error occurred during the game loop: " + std::string(e.what()), Debug::ERROR);
    }
}

void Ludkerno::StopLudkerno(){
    Running_ = false;
}