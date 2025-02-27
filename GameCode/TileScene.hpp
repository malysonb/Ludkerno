#pragma once
#include "../LudkernoLib.hpp"

class TileScene : public Scene
{
private:
    /* data */
public:
    Entity *isoTile;
    void Setup()
    {
        isoTile = EntityMngr::GetInstance()->Add();
        isoTile->SetSprite(".\\Assets\\tile_grass.png", 32,32, 1);
        isoTile->GetSprite()->SetOrigin(16,16);
        isoTile->transform->SetScreenPosition(Ludkerno::screen.DynamicHPosition(50), Ludkerno::screen.DynamicVPosition(50));
        isoTile->AddComponent<Poligonal>(isoTile);
        Vector2 poligon[] = {
            //Vector2(-16,6),
            Vector2(-16,-4),
            Vector2(0,-14),
            Vector2(16,-4),
            Vector2(0,6)
            //Vector2(16,6),
            //Vector2(0,14)
        };
        isoTile->getComponent<Poligonal>()->Init(poligon, 4);
    }

    void Update()
    {
        Vector2 mousePos = Vector2(Ludkerno::key.keycode.MouseX, Ludkerno::key.keycode.MouseY);
        SDL_SetRenderDrawColor(Ludkerno::renderer, 255, 255, 255, 255);
        if(Ludkerno::key.keycode.LEFT_CLICK)
        {
            std::cout << isoTile->getComponent<Poligonal>()->isInside(&mousePos);
        }
    }
};