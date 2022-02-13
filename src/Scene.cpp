#include "../include/Ludkerno.hpp"
#include "../include/Camera.hpp"
#include "../include/Scene.hpp"
#include "../include/TextureMngr.hpp"
#include "../include/Tilemap.hpp"
#include "../include/TileLayer.hpp"
#include "../include/RenderPipeline.hpp"
#include "../include/Object2D.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

TileLayer *Scene::CreateLayer(int sX, int sY, int *MapCode){
    TileLayer *newLayer = new TileLayer();
    newLayer->LoadMap(sX, sY, MapCode);
    this->layers.push_back(newLayer);
    Ludkerno::renderPipeline.add2Pipeline(newLayer);
    return newLayer;
}