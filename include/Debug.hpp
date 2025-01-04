#pragma once
#include <iostream>
#include "Ludkerno.hpp"
#define IN_DEBUG 1
#ifdef IN_DEBUG
#include <string>
#endif

/**
 * @brief 
 * Debug class
 */
class Debug
{
    int logLevel = INFO;
    public:
    enum Level{
        INFO, WARN, ERROR
    };
    static void log(const char* m, Level level);
    static void log(std::string m, Level level);
    static void log(std::string m);
};