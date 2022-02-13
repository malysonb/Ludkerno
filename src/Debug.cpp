#include "../include/Debug.hpp"

void Debug::log(const char *message, Level level = Debug::INFO)
{
    if (IN_DEBUG == 1)
        switch (level)
        {
        case Debug::INFO:
            std::cout << "INFO: " << message << std::endl;
            break;
        case Debug::WARN:
            std::cout << "WARN: " << message << std::endl;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,
                                     "WARNING!",
                                     message, Ludkerno::window);
            break;
        case Debug::ERROR:
            std::cout << "ERROR: " << message << std::endl;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                     "ERROR!",
                                     message, Ludkerno::window);
            break;
        default:
            break;
        }
}

void Debug::log(std::string message, Level level = Debug::INFO)
{
    if (IN_DEBUG == 1)
        switch (level)
        {
        case Debug::INFO:
            std::cout << "INFO: " << message << std::endl;
            break;
        case Debug::WARN:
            std::cout << "WARN: " << message << std::endl;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,
                                     "WARNING!",
                                     message.c_str(), Ludkerno::window);
            break;
        case Debug::ERROR:
            std::cout << "ERROR: " << message << std::endl;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                     "ERROR!",
                                     message.c_str(), Ludkerno::window);
            break;
        default:
            break;
        }
}

void Debug::log(std::string message)
{
    if (IN_DEBUG == 1)
        std::cout << "INFO: " << message << std::endl;
}