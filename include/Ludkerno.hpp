#pragma once

#define VERSION "v0.6.0 Alpha"
#ifdef SDL_Path
#include SDL_Path
#else
#include "SDL2/SDL.h"
#endif

class List;
class Camera;
class Screen;
class Scene;
class SceneMngr;
class RenderPipeline;
class Key;
struct Vector2;

class Ludkerno
{
private:
    static bool Running_;
    static Ludkerno *instance_;

protected:
    Ludkerno();
    ~Ludkerno();
    /**
     * Handles all the inputs like the Controllers, KeyBoard or Mouse.
     **/
    void HandleEvents();

    /**
     * Triggers every Tick. 
     **/
    void Update();

    /**
     * Renders all the stuff on the screen.
     **/
    void Render();

public:
    static SDL_Window *window;
    static float FrameRate;
    static float DeltaTime;
    static Key key;
    static Vector2 matrix;
    static Vector2 camVelocity;
    static Vector2 WindowSize;
    static Screen screen;
    static Camera *camera;
    static SDL_Event Event;
    static SDL_Renderer *renderer;

    Ludkerno(Ludkerno &other) = delete;

    void operator=(const Ludkerno &) = delete;

    static void Loop();

    /**
     * Initiates the Engine.
     * @param WindowTitle The title of the game.
     * @param WindowWidth Sets the Width of the window.
     * @param WindowHeight Sets the Height of the window.
     **/
    static void EngineInit(const char *WindowTitle, int WindowWidth, int WindowHeight, int Lx = 426, int Ly = 240);

    static Ludkerno *GetInstance();

    static Scene *GetScene();

    static Uint32 GetCurrentTicks();

    /**
     * Turns off the Engine.
     **/
    static void Clear();

    /**
     * @returns True if the engine is running.
     **/
    static bool IsRunning();

    /**
     * Loads/Changes the Scene of the game.
     * @param scene The Scene class you will load.
     **/
    static void LoadScene(Scene *scene);

    static void StopLudkerno();
};

/**
 * Contributors:
 * - @malysonb
 */