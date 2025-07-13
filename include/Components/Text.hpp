#pragma once
#include "Ludkerno.hpp"
#include "Component.hpp"
#include "Vector2.hpp"
#include "SDL2/SDL_ttf.h" // Include SDL_ttf for text rendering
#include <string>

class Text : public Component
{
private:
    // Private members can be added here if needed
    // For example, you might want to store the texture for the rendered text
    SDL_Texture *texture = nullptr; // Texture for the rendered text
    SDL_Surface *surface = nullptr; // Surface for the rendered text
    SDL_Color color = {255, 255, 255, 255}; // Default white color for text
    Vector2 size; // Size of the rendered text
public:
    std::string content;
    Vector2 position;
    int fontSize;
    TTF_Font *font = nullptr; // Font for rendering text
    bool isUI = false; // Flag to indicate if this text is part of the UI

    Text(){
        content = "Sample Text";
        position = Vector2(0, 0);
        fontSize = 24;
        if (TTF_WasInit() == 0) {
            if (TTF_Init() == -1) {
                Debug::log("Failed to initialize SDL_ttf: " + std::string(TTF_GetError()), Debug::Level::ERROR);
            }
        }
        font = TTF_OpenFont("/usr/share/fonts/adwaita-mono-fonts/AdwaitaMono-Regular.ttf", fontSize);
        if (!font) {
            Debug::log("Failed to load font: " + std::string(TTF_GetError()), Debug::Level::ERROR);
        }
        isUI = true;
    }

    void Render(){
        if (font) {
            // Se o fontSize mudou, recarregue a fonte com o novo tamanho
            if (font && TTF_FontHeight(font) != fontSize) {
                TTF_CloseFont(font);
                font = TTF_OpenFont("/usr/share/fonts/adwaita-mono-fonts/AdwaitaMono-Regular.ttf", fontSize);
                if (!font) {
                    Debug::log("Failed to load font: " + std::string(TTF_GetError()), Debug::Level::ERROR);
                    return;
                }
            }
            // Use TTF_RenderUTF8_Solid_Wrapped to support line breaks (multiline)
            // Set a max width for wrapping, e.g., 400 pixels (adjust as needed)
            Uint32 wrapLength = 400;
            surface = TTF_RenderUTF8_Solid_Wrapped(font, content.c_str(), color, wrapLength);
            if (!surface) {
                Debug::log("Failed to render text surface: " + std::string(TTF_GetError()), Debug::Level::ERROR);
                return;
            }
            texture = SDL_CreateTextureFromSurface(Ludkerno::renderer, surface);
            if (!texture) {
                Debug::log("Failed to create texture from surface: " + std::string(SDL_GetError()), Debug::Level::ERROR);
                SDL_FreeSurface(surface);
                return;
            }
            SDL_Rect destRect = {static_cast<int>(position.X), static_cast<int>(position.Y), surface->w, surface->h};
            SDL_RenderCopy(Ludkerno::renderer, texture, nullptr, &destRect);
            SDL_FreeSurface(surface); // Free the surface after creating the texture
            SDL_DestroyTexture(texture); // Destroy the texture after rendering
        }
    }

    void SetText(const std::string &text)
    {
        content = text;
        // Update the texture or surface if needed
    }

    void SetPosition(const Vector2 &pos)
    {
        position = pos;
        // Update the position of the text if needed
    }

    void SetFontSize(int size)
    {
        fontSize = size;
        // Update the font size if needed
    }

    void setFont(const std::string &fontPath)
    {
        if (font) {
            TTF_CloseFont(font); // Close the previous font if it exists
        }
        font = TTF_OpenFont(fontPath.c_str(), fontSize);
        if (!font) {
            Debug::log("Failed to load font: " + std::string(TTF_GetError()), Debug::Level::ERROR);
        }
    }

    ~Text() override
    {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
        if (surface) {
            SDL_FreeSurface(surface);
        }
        if (font) {
            TTF_CloseFont(font);
        }
    }

    void Update() override{}

    void Init() override
    {
        Active = true;
        // Initialize the text component, e.g., load a font
    }

    void Init(const std::string &text, const Vector2 &pos, int size)
    {
        content = text;
        position = pos;
        fontSize = size;
        Active = true;
        isUI = true;
        // Additional initialization if necessary
    }

    const char *GetName() override
    {
        return "Text";
    }

    void Disable() override
    {
        Active = false;
        // Additional cleanup if necessary
    }
};