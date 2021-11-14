#include <iostream>
#include <algorithm>
#include <vector>
#include "../include/RenderPipeline.hpp"
#include "../include/Object2D.hpp"

bool comparaLayer(Object2D *obj1, Object2D *obj2){
    return obj1->getLayer() < obj2->getLayer();
}

void RenderPipeline::Render()
{
    std::sort(m_pipeline.begin(), m_pipeline.end(), comparaLayer);
    for (std::size_t i = 0; i < m_pipeline.size(); ++i)
    {
        m_pipeline[i]->Render();
    }
}

void RenderPipeline::add2Pipeline(Object2D *obj)
{
    m_pipeline.push_back(obj);
}

void RenderPipeline::remove(Object2D *obj)
{
    for (std::size_t i = 0; i < m_pipeline.size(); ++i)
    {
        if(m_pipeline[i] == obj){
            m_pipeline.erase(m_pipeline.begin() + i);
        }
    }
}

void RenderPipeline::Clear()
{
    m_pipeline.clear();
}