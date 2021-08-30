#pragma once
#include "Object2D.hpp"
#include <vector>

class RenderPipeline
{
private:
    std::vector<Object2D*> m_pipeline;
public:
    void Render();
    void add2Pipeline(Object2D *obj);
    void remove(Object2D *obj);
    void Clear();
};