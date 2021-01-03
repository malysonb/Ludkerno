#include "../include/Utils.hpp"
#include <iostream>
#include <chrono>

bool Utils::IsBetween(int value, int min, int max)
{
    if(value >= min && value <= max)
    {
        return true;
    }
    else
        return false;
}

int Utils::Rand(int min, int max)
{
    srand(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    return rand() % (max - min) + min;
}