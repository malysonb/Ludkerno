#pragma once
#include "../Game.hpp"
#include "../Component.hpp"
#include "Transform.hpp"

class Sprite : public Component
{
public:
    SDL_Rect srcRect, destRect;
    int v_px, h_px;
    int **sheet_Dimension;

    Sprite();
    ~Sprite();

    ///Load Spritesheet
    void LoadSpritesheet(SDL_Texture *);

    ///SetAnimation based in the Spritesheet.
    void SetAnimation(int Anim_Index);

    void SetupAnimation(int wichAnim, int finalFrame, int speed);
    void Init(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations);
    void SetOrigin(float x, float y);
    void Update() override;
    void Render();
    const char* GetName() {return "Sprite";}

    Transform OriginPoint;

    int n_ofAnims = 0;

private:
    SDL_Point m_Point;
    SDL_Texture* sprite;
    int m_CurrentAnim = 0;
    int m_CurrentFrame = 0;
    int m_final_Frame = 0;
    Uint32 m_LastTime = 0;
    Uint32 m_CurrentTime = 0;
};