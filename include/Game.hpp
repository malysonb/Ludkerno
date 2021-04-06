#pragma once
#define SDL_MAIN_HANDLED
#define VERSION "v0.5.0 Alpha"
#ifdef SDL_Path
#include SDL_Path
#else
#include <SDL2/SDL.h>
#endif
#include "Key.hpp"

class List;
class Camera;
class Screen;
class Scene;
class SceneMngr;
struct Vector2;

class Game
{
    bool Running = false;
public:
    static SDL_Window *window;
    static float FrameRate;
    static float DeltaTime;
    static Key key;
    static List EntityManager;
    static Vector2 matrix;
    static Vector2 camVelocity;
    static Vector2 WindowSize;
    static SceneMngr sceneMngr;
    static Screen screen;
    static Camera *camera;
    static SDL_Event Event;
    static SDL_Renderer *renderer;

    /**
     * Initiates the Engine.
     * @param WindowTitle The title of the game.
     * @param WindowWidth Sets the Width of the window.
     * @param WindowHeight Sets the Height of the window.
     **/
    void EngineInit(const char * WindowTitle, int WindowWidth, int WindowHeight, int Lx = 426, int Ly = 240);

    static Scene *GetScene();

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

    /**
     * Turns off the Engine.
     **/
    void Clear();

    /**
     * @returns True if the engine is running.
     **/
    bool IsRunning();

    /**
     * Loads/Changes the Scene of the game.
     * @param scene The Scene class you will load.
     **/
    static void LoadScene(Scene *scene);
};

/**
 * Contributors:
 * - @malysonb
 */