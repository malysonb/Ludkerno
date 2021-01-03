#include "../include/EntityMNGR.hpp"
#include "../include/Entity.hpp"
#include <vector>

Obj::Obj(int ID)
{
    object = new Entity();
    object->ID = ID;
}
Obj::~Obj()
{
    delete object;
}
Entity *Obj::GetEntity()
{
    return object;
}

Entity *List::Add()
{
    Obj *temp = new Obj(IDs);
    SceneEntities.push_back(temp);
    Length++;
    IDs++;
    return temp->object;
}

void List::Remove(int id)
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        if (id == SceneEntities[i]->object->ID)
        {
            SceneEntities.erase(SceneEntities.begin() + i);
        }
    }
}

void List::Clear()
{
    SceneEntities.clear();
    Length = 0;
    IDs = 0;
}

void List::Update()
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        SceneEntities[i]->object->Update();
    }
}

void List::Render()
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        SceneEntities[i]->object->Render();
    }
}

Entity *List::GetByID(int id)
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        if(id == SceneEntities[i]->object->ID)
        {
            return SceneEntities[i]->object;
        }
    }
    return nullptr;
}