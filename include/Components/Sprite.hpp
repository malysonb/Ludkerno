#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * @date 23/07/2020
 * "This is my favorite code."
 */
#include "../Game.hpp"
#include "../Component.hpp"
#include "../TextureMngr.hpp"
#include "../Vector2.hpp"

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

    Sprite()
    {
        /*TODO*/
    }
    ~Sprite()
    {
        for(int i = 0; i < n_ofAnims; i++)
        {
            delete(sheet_Dimension[i]);
        }
        delete(sheet_Dimension);
    }

    ///Load Spritesheet
    void LoadSpritesheet(SDL_Texture *newSprite)
    {
        sprite = newSprite;
    }

    ///SetAnimation based in the Spritesheet.
    void SetAnimation(int Anim_Index)
    {
        if (Anim_Index >= n_ofAnims || Anim_Index < 0)
            Debug::log("Array index out of bounds! at sprite set animation", Debug::ERROR);
        else
        {
            m_CurrentAnim = Anim_Index;
            m_final_Frame = sheet_Dimension[m_CurrentAnim][0];
            if(m_CurrentFrame > m_final_Frame)
            {
                m_CurrentFrame = 0;
            }
            m_CurrentTime = m_LastTime;
            m_changed = true;
        }
    }

    int getCurrentAnim()
    {
        return m_CurrentAnim;
    }

    void SetupAnimation(int animIndex, int finalFrame, int speed)
    {
        if (animIndex >= n_ofAnims || animIndex < 0)
            Debug::log("Array index out of bounds! at sprite setup animation", Debug::ERROR);
        else
        {
            sheet_Dimension[animIndex][0] = finalFrame;
            sheet_Dimension[animIndex][1] = speed;
        }
    }
    void Init(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations)
    {
        Active = true;
        m_Point.x = Size_x / 2;
        m_Point.y = Size_y / 2;
        //Debug::log("Initializing Sprite", Debug::INFO);
        if (release_v)
            LoadSpritesheet(TextureMngr::LoadTexture_RW(texturePath));
        else
            LoadSpritesheet(TextureMngr::LoadTexture(texturePath));
        h_px = Size_y;
        v_px = Size_x;
        n_ofAnims = n_ofAnimations;
        sheet_Dimension = new int *[n_ofAnimations];
        for (int i = 0; i < n_ofAnimations; i++)
        {
            sheet_Dimension[i] = new int[2];
        }
    }

    void SetOrigin(float x, float y)
    {
        OriginPoint.X = x;
        OriginPoint.Y = y;
    }

    void Update() override
    {
        srcRect.h = h_px;
        srcRect.w = v_px;
        m_final_Frame = sheet_Dimension[m_CurrentAnim][0];
        m_CurrentTime = SDL_GetTicks();
        if (m_CurrentTime > m_LastTime + sheet_Dimension[m_CurrentAnim][1] || m_changed == true)
        {
            if (m_CurrentFrame <= m_final_Frame)
            {
                srcRect.x = srcRect.w * m_CurrentFrame;
                srcRect.y = srcRect.h * m_CurrentAnim;
                m_CurrentFrame = m_CurrentFrame == m_final_Frame ? 0 : m_CurrentFrame + 1;
            }
            m_LastTime = m_CurrentTime;
            m_changed = false;
        }
    }

    void flipHorizontally(bool isFlipped)
    {
        if(isFlipped)
        {
            flipped = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipped = SDL_FLIP_NONE;
        }
    }

    void Render() override
    {
        SDL_RenderCopyEx(Game::renderer, sprite, &srcRect, &destRect, 0, NULL, flipped);
    }

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