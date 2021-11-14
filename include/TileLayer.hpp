#pragma once
#include "Game.hpp"
#include "Tilemap.hpp"
#include "Object2D.hpp"

class TileLayer : public Object2D
{
private:
    SDL_Texture* m_TileMap;
    Tilemap* m_tile;
    SDL_Rect src, dest;
    float m_parallax = 1;
    bool canDraw = false;
public:

    ~TileLayer();

    /**
     * @brief Load a map buffer to the Layer
     * 
     * @param sX Horizontal size.
     * @param sY Vertical size.
     * @param MapCode Map buffer.
     */
    void LoadMap(int sX, int sY, int *MapCode);

    /**
     * @brief Draw map on the screen.
     * 
     */
    void Render();

    /**
     * @brief Set the Tilemap object
     * 
     * @param filename Filename of the texture.
     * @param sheets_H How many sprites horizontal.
     * @param sheets_V How many sprites vertically;
     * @param tile_X Horizontal size of the sprites.
     * @param tile_Y Vertical size of the sprites.
     */
    void SetTilemap(const char *filename, int sheets_H, int sheets_V, int tile_X = 32, int tile_Y = 32);

    /**
     * @brief Set the Parallax value
     * 
     */
    void setParallax(float value);

    /**
     * @brief Get the Parallax value
     * 
     * @return float 
     */
    float getParallax();

    /**
     * @brief Cols and rows of the map.
     * 
     */
    int cols, rows;

    /**
     * @brief Map buffer.
     * 
     */
    int **map;
};

