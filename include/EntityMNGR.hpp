#pragma once
#include "Game.hpp"
#include "Entity.hpp"

class Obj
{
public:
    Entity *object;
    Obj *NextObj = nullptr;
    Obj(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations, int ID)
    {
        object = new Entity(texturePath, Size_x, Size_y, n_ofAnimations);
        object->ID = ID;
    }
    ~Obj()
    {
        delete object;
    }
};

struct List
{
    int Length = 0;
    Obj *Start = nullptr, *End = nullptr;
    Entity *Add(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations)
    {
        Obj *temp = new Obj(texturePath, Size_x, Size_y, n_ofAnimations, Length);
        
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
        return temp->object;
    }
    void Remove(int id)
    {
        Obj *LastCalled = nullptr;
        Obj *s_Index = Start;
        for (int i = 0; i < Length; i++)
        {
            if (s_Index->object->ID == id)
            {
                if (i == 0)
                {
                    Start = s_Index->NextObj;
                    delete s_Index;
                    Length--;
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
                        break;
                    }
                }
                else
                {
                    LastCalled->NextObj = s_Index->NextObj;
                    delete s_Index;
                    Length--;
                    break;
                }
            }
            if (s_Index->NextObj != nullptr)
            {
                LastCalled = s_Index;
                s_Index = s_Index->NextObj;
            }
        }
        Debug::log("ENTITY NOT FOUND! IS HAPPENING MEMORY LEAK?", Debug::WARN);
    }
    void Clear()
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
    void Update()
    {
        Obj *s_index = Start;
        for (int i = Length; i > 0; i--)
        {
            s_index->object->Update();
            if(s_index->NextObj != nullptr)
            {
                s_index = s_index->NextObj;
            }
        } 
    }
    void Render()
    {
        Obj *s_index = Start;
        for (int i = Length; i > 0; i--)
        {
            s_index->object->Render();
            if(s_index->NextObj != nullptr)
            {
                s_index = s_index->NextObj;
            }
        } 
    }
};