#pragma once
#include "Object.hpp"

class Object2D : public Object
{
private:
    /* data */
    int m_Layer = 0;
public:
    virtual void Render() = 0;
    void setLayer(int layer);
    int getLayer();
};
