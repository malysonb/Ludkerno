#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * @date 23/07/2020
 * "This is my favorite code."
 */
#include "../Ludkerno.hpp"
#include "../Component.hpp"
#include "../TextureMngr.hpp"
#include "../Vector2.hpp"
#include "../Transform.hpp"

/**
 * @brief 
 * This is the Sprite component of an Entity.
 */
class Sprite : public Component
{
#ifdef Release
    bool release_v = true;
#else
    bool release_v = false;
#endif
public:
    SDL_Rect srcRect, destRect;
    int v_px, h_px;
    int **sheet_Dimension;
    Transform *baseTransform;

    Sprite()
    {
    }
    ~Sprite() override
    {
        delete [] sheet_Dimension;
    }

    void LoadSpritesheet(SDL_Texture *newSprite);

    void SetAnimation(int Anim_Index);

    int getCurrentAnim();

    void SetupAnimation(int animIndex, int finalFrame, int speed);

    void Init(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations);

    void SetOrigin(int x, int y);

    void Update() override;

    void flipHorizontally(bool isFlipped);

    void Render() override;

    const char *GetName() { return "Sprite"; }

    Vector2 OriginPoint;

    int n_ofAnims = 0;

private:
    SDL_RendererFlip flipped = SDL_FLIP_NONE;
    SDL_Point m_Point;
    SDL_Texture *sprite;
    bool m_changed = false;
    int m_CurrentAnim = 0;
    int m_CurrentFrame = 0;
    int m_final_Frame = 0;
    Uint32 m_LastTime = 0;
    Uint32 m_CurrentTime = 0;
};