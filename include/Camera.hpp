#pragma once

#include "Game.hpp"
#include "Components/Transform.hpp"
#include "Components/Input.hpp"

class Camera
{
    private:
    public:
    Transform transform;
    Input CamInput;
    void Init()
    {
        CamInput.Init(&transform);
    }
    void Update()
    {
        CamInput.Update();
        transform.Update();
    }
};