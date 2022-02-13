#pragma once
#include "Object2D.hpp"
#include <vector>

class RenderPipeline
{
private:
    static RenderPipeline *instance_;
    std::vector<Object2D*> m_pipeline;
    RenderPipeline();
    ~RenderPipeline();
public:

    //Singleton
    RenderPipeline(RenderPipeline &other) = delete;
    void operator=(RenderPipeline&) = delete;
    static RenderPipeline* GetInstance();
    ///////////////////////////////////////////////
    void Render();
    void add2Pipeline(Object2D *obj);
    void remove(Object2D *obj);
    void Clear();
};