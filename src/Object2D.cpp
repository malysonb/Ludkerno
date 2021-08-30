#include "../include/Object2D.hpp"

void Object2D::setLayer(int layer)
{
    this->m_Layer = layer;
}
int Object2D::getLayer()
{
    return this->m_Layer;
}