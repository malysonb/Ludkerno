#pragma once
#include "../LudkernoLib.hpp"
#include "PlatformerInput.hpp"
#include "Components/Text.hpp"

int testmap[] = {6,7,7,7,7,7,7,7,7,7,8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,1,1,1,4,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,4,4,4,4,4,
                 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,4,4,4,4,4,4,
                 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4};

class PlatformScene : public Scene
{
    public:
    Entity* Player;
    Entity* UI;
    void Setup()
    {
        setWindowTitle("Ludkerno - Platformer Scene Example");
        TileLayer *layer = CreateLayer(35,15,testmap);
        layer->SetTilemap("./Assets/tileset.png",3,3,16,16);
        Player = EntityMngr::GetInstance()->Add();
        Player->SetSprite("./Assets/aliisheet.png",16,16,4);
        Player->GetSprite()->SetOrigin(8,16);
        Player->GetSprite()->SetupAnimation(0,1,1000);
        Player->GetSprite()->SetupAnimation(1,5,50);
        Player->GetSprite()->SetupAnimation(2,0,1000);
        //Player->transform->SetScale(2,2);
        Player->setLayer(1);
        Player->AddComponent<PlatformerInput>(Player);
        Player->getComponent<PlatformerInput>()->Init();
        //UI = EntityMngr::GetInstance()->Add();
        //UI->AddComponent<Text>(UI);
        //UI->getComponent<Text>()->Init("Score: 0", Vector2(10, 10), 8);
        //Player->AddComponent<Collider>(Player);
        //Player->getComponent<Collider>()->Init();
        Ludkerno::camera->canMove = true;
        std::cout << Player->toString() << std::endl;
        Player->transform->SetPosition(200, -50);
    }
    void Update()
    {
        SDL_SetRenderDrawColor(Ludkerno::renderer, 0, 0, 0, 255);
        std::string title = "Ludkerno - FPS: " + std::to_string(static_cast<int>(Ludkerno::FrameRate)) + " - DeltaTime: " + std::to_string(Ludkerno::DeltaTime);
        Player->debug = true;
        //UI->getComponent<Text>()->SetText(title);
        setWindowTitle(title);
        if(Ludkerno::key.keycode.START)
            Player->debug = !Player->debug;
    }
};