#pragma once
#include "Ludkerno.hpp"
#include "Scene.hpp"
#include <vector>

class SceneMngr
{
    private:
    int iterator;
    static SceneMngr *instance_;
    SceneMngr();
    ~SceneMngr();

    public:
    SceneMngr(SceneMngr &other) = delete;
    void operator=(const SceneMngr&) = delete;
    static SceneMngr* GetInstance();
    std::vector<Scene*> sceneVector;
    void setup(int number_of_scenes);
    void setScene(int index_of_the_scene);
    void insertScene(Scene *scene);
    Scene *GetScene(int index_of_the_scene);
};