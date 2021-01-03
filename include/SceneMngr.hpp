#pragma once
#include "Game.hpp"
#include "Scene.hpp"
#include <vector>

class SceneMngr
{
    private:
    int iterator;
    public:
    std::vector<Scene*> sceneVector;
    void setup(int number_of_scenes);
    void setScene(int index_of_the_scene);
    void insertScene(Scene *scene);
    Scene *GetScene(int index_of_the_scene);
};