#pragma once
#include "../Ludkerno.hpp"
#include "../Component.hpp"
#include "../Vector2.hpp"
#include "../Transform.hpp"
#include "../Entity.hpp"

class Poligonal : public Component
{
private:
    /* data */
    int m_pointQnt = 0;
    Vector2 m_startPoint;
    Vector2 *shape;
    Vector2 *origin;

public:
    Poligonal(/* args */){}
    
    ~Poligonal(){}

    void Init(Vector2 *poligon, int num)
    {
        Active = true;
        this->shape = new Vector2[num];
        for (int i = 0; i < num; i++)
        {
            this->shape[i].X = poligon[i].X;
            this->shape[i].Y = poligon[i].Y;
        }
        
        origin = &this->Base->GetSprite()->OriginPoint;
        for (int i = 0; i < num; i++)
        {
            shape[i] = shape[i] + origin;
            std::cout << "X: " << shape[i].X << " Y: " << shape[i].Y << std::endl;
            m_pointQnt++;
        }
    }

    void Update()
    {
    }
    void Render()
    {
         for (int i = 0; i < m_pointQnt; i++)
        {
            Vector2 actualPos = this->Base->transform->GetPosition();
            Vector2 tam(this->Base->GetSprite()->OriginPoint);
            Vector2 next = shape[i + 1 != m_pointQnt ? i + 1 : 0] + actualPos;
            Vector2 point = (shape[i] + actualPos);
            Vector2 middle = next + point; // Going around the shape
            middle = middle / 2;
            Vector2 mouse (Ludkerno::key.keycode.MouseX, Ludkerno::key.keycode.MouseY);
            middle = middle - tam;
            SDL_SetRenderDrawColor(Ludkerno::renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(Ludkerno::renderer,
                       middle.X, middle.Y,mouse.X,mouse.Y);
            point = point - tam;
            next = next - tam;
            SDL_SetRenderDrawColor(Ludkerno::renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(Ludkerno::renderer,
                       point.X, point.Y, next.X, next.Y);
        }
    }

    bool isInside(Vector2 *vector)
    {
        int verifies = 0;
        for (int i = 0; i < m_pointQnt; i++)
        {
            Vector2 actualPos = this->Base->transform->GetPosition();
            Vector2 tam(this->Base->GetSprite()->OriginPoint);
            Vector2 next = shape[i + 1 != m_pointQnt ? i + 1 : 0] + actualPos;
            Vector2 point = (shape[i] + actualPos);
            next = next - tam;
            point = point - tam;
            Vector2 middle = next + point; // Going around the shape
            middle = middle / 2;
            Vector2 direction = next - point;
            Vector2 buff(vector->X, vector->Y);
            Vector2 difference = buff - middle;
            difference = difference.Direction();
            Vector2 normal = direction.Normal();
            float dotProd = normal.DotProduct(&difference);
            verifies += dotProd > 0 ? 1 : 0;
        }
        if(verifies == m_pointQnt)
            return true;
        else return false;
    }

    const char *GetName() { return "Poligonal"; }
};