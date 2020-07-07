#pragma once
#define SDL_MAIN_HANDLED
#define VERSION "v0.1.1 Alpha"
#include "../ThirdParty/x64/include/SDL2/SDL.h"
#include "Key.hpp"

class List;
class Camera;
class Screen;
struct Vector2;

class Game
{
    SDL_Window *window;
    bool Running = false;
public:
    static Key key;
    static List EntityManager;
    static Vector2 matrix;
    static Vector2 camVelocity;
    static Vector2 WindowSize;
    static Screen screen;
    static Camera *camera;
    static SDL_Event Event;
    static SDL_Renderer *renderer;
    Game();
    ~Game();
    void EngineInit(const char *, int, int);
    void HandleEvents();
    void Update();
    void Render();
    void Clear();
    void Setup();
    void Loop();
    int GetID();
    bool IsRunning();

    static int Rand(int min, int max);
};
