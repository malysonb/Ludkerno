#pragma once
#include "Ludkerno.hpp"
#include "Entity.hpp"
#include <vector>

class Obj
{
public:
    Entity *object;
    Obj(int ID);
    ~Obj();
    Entity *GetEntity();
};

class EntityMngr
{
private:
    static EntityMngr *instance_;
    EntityMngr();
    ~EntityMngr();
public:

    //Singleton functions
    EntityMngr(EntityMngr &other) = delete;
    void operator=(const EntityMngr&) = delete;
    static EntityMngr *GetInstance();
    ///////////////////////////

    int Length = 0;
    int IDs = 0;
    std::vector<Obj *> SceneEntities;
    Entity *Add();
    void RemoveID(int id);
    Obj *RemoveIndex(int index);
    void Clear();
    void Update();
    void Render();
    Entity *GetByID(int id);
};