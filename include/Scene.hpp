#pragma once
/**
 * @author Malyson Breno de Souza
 * @version 1.0
 * Simple scene template to you make your own scenes.
 */
#include "Game.hpp"
#include "Tilemap.hpp"
#include "TileLayer.hpp"
#include <vector>

class RenderPipeline;

class Scene
{
    public:
    Scene();
    ~Scene();
    std::vector<TileLayer*> layers;

    virtual void Setup() = 0;

    virtual void Update() = 0;

    /**
     * @brief Load a map buffer to the Layer
     * 
     * @param sX Horizontal size.
     * @param sY Vertical size.
     * @param MapCode Map buffer.
     */
    TileLayer *CreateLayer(int sX, int sY, int *MapCode);

    private:

};