#include "Ludkerno.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "System/TextureMngr.hpp"
#include "Tilemap.hpp"
#include "TileLayer.hpp"
#include "System/RenderPipeline.hpp"
#include "Object2D.hpp"

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
    RenderPipeline::GetInstance()->add2Pipeline(newLayer);
    return newLayer;
}