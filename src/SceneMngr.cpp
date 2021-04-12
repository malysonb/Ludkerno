#include "../include/SceneMngr.hpp"
#include "../include/Game.hpp"
#include "../include/Debug.hpp"

/*void SceneMngr::setup(int number_of_scenes)
{
    sceneVector = new Scene*[number_of_scenes];
}*/
void SceneMngr::setScene(int index_of_the_scene)
{
    Game::LoadScene(sceneVector[index_of_the_scene]);
}
void SceneMngr::insertScene(Scene *scene)
{
    sceneVector.push_back(scene);
    iterator++;
}
Scene *SceneMngr::GetScene(int index_of_the_scene)
{
    if(index_of_the_scene > (int)sceneVector.size() || (int)sceneVector.size() == 0)
    {
        Debug::log("index out of bound — GetScene(int)!", Debug::Level::ERROR);
        return nullptr;
    }
    return sceneVector[index_of_the_scene];
}