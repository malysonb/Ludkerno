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
    if (object)
        delete object;
}
Entity *Obj::GetEntity()
{
    return object;
}

EntityMngr *EntityMngr::instance_ = nullptr;

EntityMngr::EntityMngr()
{
}

EntityMngr::~EntityMngr()
{
}

EntityMngr *EntityMngr::GetInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = new EntityMngr();
    }
    return instance_;
}

Entity *EntityMngr::Add()
{
    Obj *temp = new Obj(IDs);
    SceneEntities.reserve(1);
    SceneEntities.push_back(temp);
    Length++;
    IDs++;
    return temp->object;
}

void EntityMngr::RemoveID(int id)
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        if (id == SceneEntities[i]->object->ID)
        {
            Obj *objtemp = SceneEntities[i];
            SceneEntities.erase(SceneEntities.begin() + i);
            Length--;
            if (objtemp)
                delete objtemp;
            return;
        }
    }
}

Obj *EntityMngr::RemoveIndex(int index)
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        if (index == i)
        {
            Obj *objtemp = SceneEntities[i];
            SceneEntities.erase(SceneEntities.begin() + i);
            Length--;
            return objtemp;
        }
    }
    return nullptr;
}

void EntityMngr::Clear()
{
    while (SceneEntities.size() > 0)
    {
        Obj *a = this->RemoveIndex(SceneEntities.size() - 1);
        if (a)
            delete a;
        std::cout << "Size: " << SceneEntities.size() << std::endl;
    }
    SceneEntities.shrink_to_fit();
    Length = 0;
    IDs = 0;
}

void EntityMngr::Update()
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        SceneEntities[i]->object->Update();
    }
}

void EntityMngr::Render()
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        SceneEntities[i]->object->Render();
    }
}

Entity *EntityMngr::GetByID(int id)
{
    for (int i = 0; i < static_cast<int>(SceneEntities.size()); i++)
    {
        if (id == SceneEntities[i]->object->ID)
        {
            return SceneEntities[i]->object;
        }
    }
    return nullptr;
}