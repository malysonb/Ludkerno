#include "../include/Components/Sprite.hpp"
#include "../include/Debug.hpp"
#include "../include/TextureMngr.hpp"

Sprite::Sprite()
{
    //Debug::log(v_px, Debug::INFO);
}
Sprite::~Sprite()
{
    free(sheet_Dimension);
}

///Load Spritesheet
void Sprite::LoadSpritesheet(SDL_Texture *newSprite)
{
    sprite = newSprite;
}

void Sprite::SetupAnimation(int animIndex, int finalFrame, int speed)
{
    if(animIndex >= n_ofAnims || animIndex < 0)
        Debug::log("Array index out of bounds!", Debug::ERROR);
    else{
    sheet_Dimension[animIndex][0] = finalFrame;
    sheet_Dimension[animIndex][1] = speed;
    }
}

void Sprite::SetAnimation(int Anim_Index)
{
    if(Anim_Index >= n_ofAnims || Anim_Index < 0)
        Debug::log("Array index out of bounds!", Debug::ERROR);
    else{
    m_CurrentAnim = Anim_Index;
    m_final_Frame = sheet_Dimension[m_CurrentAnim][0];
    }
}


void Sprite::Init(const char *texturePath, int Size_x, int Size_y, int n_ofAnimations)
{
    Active = true;
    m_Point.x = Size_x/2;
    m_Point.y = Size_y/2;
    Debug::log("Initializing Sprite",Debug::INFO);
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

void Sprite::SetOrigin(float x, float y)
{
    m_Point.x = x;
    m_Point.y = y;
}

void Sprite::Update()
{
    srcRect.h = h_px;
    srcRect.w = v_px;
    m_final_Frame = sheet_Dimension[m_CurrentAnim][0];
    m_CurrentTime = SDL_GetTicks();
    if (m_CurrentTime > m_LastTime + sheet_Dimension[m_CurrentAnim][1])
    {
        if (m_CurrentFrame <= m_final_Frame)
        {
            srcRect.x = srcRect.w * m_CurrentFrame;
            srcRect.y = srcRect.h * m_CurrentAnim;
            m_CurrentFrame = m_CurrentFrame == m_final_Frame ? 0 : m_CurrentFrame + 1;
        }
        m_LastTime = m_CurrentTime;
    }
}

void Sprite::Render()
{
    SDL_RenderCopy(Game::renderer, sprite, &srcRect, &destRect);
}
