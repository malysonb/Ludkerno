#include "../include/ComponentList.hpp"
#include "../include/Debug.hpp"
#include "../include/Game.hpp"

Entity* Master;

void Input::Init(Entity* Instance)
{
    Active = true;
    Master = Instance;
    transform = Master->transform;
    Debug::log("Initializing Input", Debug::INFO);
}

void Input::Update()
{
    transform->velocity.Y = Game::key.keycode.Y_Axis * 2;
    transform->velocity.X = Game::key.keycode.X_Axis * 2;
}
void Input::Render()
{
    /*Not Implemented*/
}