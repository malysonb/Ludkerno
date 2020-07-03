#include "../include/Debug.hpp"

void Debug::log(const char *message, Level level = Debug::INFO)
{
    switch (level)
    {
    case Debug::INFO:
        if (IN_DEBUG == 1)
            std::cout << "INFO: " << message << std::endl;
        break;
    case Debug::WARN:
        std::cout << "WARN: " << message << std::endl;
        break;
    case Debug::ERROR:
        std::cout << "ERROR: " << message << std::endl;
        break;
    default:
        break;
    }
}

void Debug::log(std::string message, Level level = Debug::INFO)
{
    switch (level)
    {
    case Debug::INFO:
        if (IN_DEBUG == 1)
            std::cout << "INFO: " << message << std::endl;
        break;
    case Debug::WARN:
        std::cout << "WARN: " << message << std::endl;
        break;
    case Debug::ERROR:
        std::cout << "ERROR: " << message << std::endl;
        break;
    default:
        break;
    }
}