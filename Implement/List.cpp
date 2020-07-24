#include "../include/EntityMNGR.hpp"
#include "../include/Entity.hpp"

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

    if (Length == 0)
    {
        Start = temp;
        End = temp;
    }
    else if (Length > 0)
    {
        End->NextObj = temp;
        End = temp;
    }
    Length++;
    IDs++;
    return temp->object;
}

void List::Remove(int id)
{
    Obj *LastCalled = nullptr;
    Obj *s_Index = Start;
    bool deleted = false;
    for (int i = 0; i < Length; i++)
    {
        if (s_Index->object->ID == id)
        {
            if (i == 0)
            {
                Start = s_Index->NextObj;
                delete s_Index;
                Length--;
                deleted = true;
                break;
            }
            else if (i == Length - 1 && Length > 1)
            {
                if (End == s_Index)
                {
                    LastCalled->NextObj = nullptr;
                    End = LastCalled;
                    delete s_Index;
                    Length--;
                    deleted = true;
                    break;
                }
            }
            else
            {
                LastCalled->NextObj = s_Index->NextObj;
                delete s_Index;
                Length--;
                deleted = true;
                break;
            }
        }
        if (s_Index->NextObj != nullptr)
        {
            LastCalled = s_Index;
            s_Index = s_Index->NextObj;
        }
    }
    if (deleted == false)
        Debug::log("ENTITY NOT FOUND!", Debug::WARN);
}

void List::Clear()
{
    int IDs[Length];
    Obj *s_index = Start;
    for (int i = 0; i < Length; i++)
    {
        IDs[i] = s_index->object->ID;
        if (s_index->NextObj != nullptr)
        {
            s_index = s_index->NextObj;
        }
    }
    int index = Length - 1;
    while (Length > 0)
    {
        Remove(IDs[index]);
        index--;
    }
}

void List::Update()
{
    Obj *s_index = Start;
    for (int i = 0; i < Length; i++)
    {
        s_index->object->Update();
        if (s_index->NextObj != nullptr)
        {
            s_index = s_index->NextObj;
        }
    }
}

void List::Render()
{
    Obj *s_index = Start;
    for (int i = 0; i < Length; i++)
    {
        s_index->object->Render();
        if (s_index->NextObj != nullptr)
        {
            s_index = s_index->NextObj;
        }
    }
}

Entity *List::GetByID(int id)
{
    Obj *s_index = Start;
    for (int i = 0; i < Length; i++)
    {
        if (id == s_index->object->ID)
        {
            return s_index->object;
        }
        else if (s_index->NextObj != nullptr)
        {
            s_index = s_index->NextObj;
        }
    }
    //Debug::log("CANT FIND THIS ENTITY!", Debug::WARN);
    return nullptr;
}