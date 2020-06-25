#include "../include/Components/Transform.hpp"

void Transform::Update()
{
    position.X += velocity.X;
    position.Y += velocity.Y;
}
void Transform::Render()
{

}

Transform::Transform()
{
    Active = true;
    position.X = 0;
    position.Y = 0;
}

void Transform::Move(float XA, float YA)
{
    position.X += XA;
    position.Y += YA;
}

void Transform::SetPosition(float XA, float YA)
{
    position.X = XA;
    position.Y = YA;
}